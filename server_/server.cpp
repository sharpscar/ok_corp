#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <mysql/mysql.h>
#include "./json.hpp"
#include <thread>

#include <iostream>
#include <string>
#include <stdexcept> // std::runtime_error 등을 위해
#include <memory>    // std::unique_ptr을 위해
#include <mariadb/conncpp.hpp> 
using json = nlohmann::json;
using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PASS = "1111";
const char* DB   = "SOCIAL";

constexpr int PORT = 9957;
constexpr int BUFFER_SIZE = 1024;


json handle_make_schedule(const json& data);  
json handle_read_schedule();
json handle_update_schedule(const json& data);
json handle_delete_schedule(const json& data);
json handle_make_dept(const json& data);
json handle_read_dept(const json& data);
json handle_update_dept(const json& data);
json handle_delete_dept(const json& data);

MYSQL* connect_db() {
    MYSQL* conn = mysql_init(nullptr);
    if (!mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0)) {
        cerr << "DB 연결 실패: " << mysql_error(conn) << endl;
        return nullptr;
    }
    cout << "DB 연결 성공" << endl;
    return conn;
}

json handle_update_dept(const json& data)
{
    json result;

    if (!data.contains("DEPT_ID") ) {
        result["status"] = "error";
        result["message"]= "필수 필드 누락";
        return result;
    }

    std::cout<< data <<endl;

       //삼항연산자로 존재하는지 확인후 담는다
       string login_id =    data.contains("LOGIN_ID")? data["LOGIN_ID"].get<string>() : "";
       string login_pw =    data.contains("LOGIN_PW")? data["LOGIN_PW"].get<string>() : "";
       string dept_name =   data.contains("DEPT_NAME")? data["DEPT_NAME"].get<string>() : "";     
       int dept_id =        data.contains("DEPT_ID")? data["DEPT_ID"].get<int>() : 0;    
       int per_lv =         data.contains("PERMISSION_LEVEL") ? data["PERMISSION_LEVEL"].get<int>():0;

       MYSQL* conn = connect_db();
       if (conn == nullptr) {
           result["status"] = "error";
           result["message"] = "DB 연결 실패";
           return result;
       }

       string query = "UPDATE DEPT SET "
       "LOGIN_ID = '" + login_id + "', "
       "LOGIN_PW = '" + login_pw + "', "
       "DEPT_NAME = '" + dept_name + "', "
       "PERMISSION_LEVEL = "+ to_string(per_lv) + " "
       "WHERE DEPT_ID = " + to_string(dept_id);

       cout << query << endl;

       if(mysql_query(conn, query.c_str())!=0){
            cerr << "쿼리 실패: " << mysql_error(conn) <<endl;
            result["status"]= "error";
            result["message"] = "DB 쿼리 실패: " +string(mysql_error(conn));
            mysql_close(conn);
            return result;
        }

        result["status"] = "success";
        result["message"] = "부서정보가 잘 수정 되었습니다..";    
        mysql_close(conn);    
        return result;  

}
json handle_make_dept(const json& data){
    json result;
    if (!data.contains("LOGIN_ID") || !data.contains("LOGIN_PW") || !data.contains("DEPT_NAME")|| !data.contains("PERMISSION_LEVEL")) {
        result["status"] = "error";
        result["message"]= "필수 필드 누락";
        return result;
    }
    //삼항연산자로 존재하는지 확인후 담는다
    string login_id = data.contains("LOGIN_ID")? data["LOGIN_ID"].get<string>() : "";
    string login_pw =  data.contains("LOGIN_PW")? data["LOGIN_PW"].get<string>() : "";
    string dept_name =  data.contains("DEPT_NAME")? data["DEPT_NAME"].get<string>() : "";        
    int per_lv =  data.contains("PERMISSION_LEVEL")? data["PERMISSION_LEVEL"].get<int>() : 0;    

    MYSQL* conn = connect_db();
    if (conn == nullptr) {
        result["status"] = "error";
        result["message"] = "DB 연결 실패";
        return result;
    }
    
    string query = "INSERT INTO DEPT (LOGIN_ID, LOGIN_PW, DEPT_NAME, PERMISSION_LEVEL) VALUES ('" 
    + login_id      + "', '" 
    + login_pw    + "', '" 
    + dept_name         + "', '"        
    + std::to_string(per_lv)+"')";

    cout << query << endl;

    if(mysql_query(conn, query.c_str())!=0){
        cerr << "쿼리 실패: " << mysql_error(conn) <<endl;
        result["status"]= "error";
        result["message"] = "DB 쿼리 실패: " +string(mysql_error(conn));
        mysql_close(conn);
        return result;
    }
    result["status"] = "success";
    result["message"] = "부서등록에 성공하였습니다.";

    mysql_close(conn);
    return result;

}

json handle_read_dept(const json& data){

    MYSQL* conn = connect_db();
    
    if (conn == nullptr) {
       cout<< "db 커넥션 오류 >>line 91";
    }

    string query = "SELECT DEPT_ID,PERMISSION_LEVEL,LOGIN_ID,DEPT_NAME from DEPT;";

    // std::cout << "이얏호!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<query;    
    if(mysql_query(conn, query.c_str())!=0){
        cerr << "쿼리 실패: " <<mysql_error(conn) << endl;
        exit(1);
    }

    MYSQL_RES* result = mysql_store_result(conn);

    if(!result){
        cerr <<"결과 없음 또는 에러 : " << mysql_error(conn) << endl;
        exit(1);
    }

    int num_fields= mysql_num_fields(result);

    json json_result = json::array(); //전체 결과를 배열로

    MYSQL_ROW row;
    while((row = mysql_fetch_row(result))){
        json data;
        data["DEPT_ID"] = row[0] ? atoi(row[0]) : 0;
        data["PERMISSION_LEVEL"] = row[1] ? atoi(row[1]) : 0;
        data["LOGIN_ID"] = row[2] ? row[2] : "";
        data["DEPT_NAME"] = row[3] ? row[3] : "";
        
        // data["LOGIN_PW"] = row[4] ?  row[4]: "";

        json_result.push_back(data);

    }
    mysql_free_result(result);

    mysql_close(conn);
    
    return json_result;

}

void handle_client(int client_socket){
    while(true){
        char buffer[BUFFER_SIZE];

        memset(buffer, 0, BUFFER_SIZE);
        
        // valread 는 클라이언트 요청에서 읽은 바이트수
        int valread = read(client_socket, buffer, BUFFER_SIZE);

        if(valread <=0){
            cout<<"클라이언트 연결 종료됨." <<endl;
            break;
        }

        //버퍼 전체가 아닌, 실제로 읽은 데이터까지만 문자열로 변환합니다.
        string received_data(buffer, valread);
        cout<<"받은 데이터 :" <<received_data <<endl;

        try{
            json request = json::parse(received_data);
            if(!request.contains("type")){    //|| !request.contains("data") 데이터가 없는 요청도 있다. 
                cerr<<"유효하지 않은 요청."<<endl;
                continue;
            }

            string type_ = request["type"];
            json data= request["data"];
            json response;

            //클라이언트가 무슨 요청하는지 여기서 판단 하여 관련 함수를 호출한다.
            if(type_ == "req_event_create"){
                
                // 일정을 db에 insert 하고 그 결과를 클라이언트에 전송하기 위한 response
                response = handle_make_schedule(data);
            }else if(type_ == "req_event_read"){
                response = handle_read_schedule();
                
            }else if(type_ == "req_event_update") {
                response = handle_update_schedule(data);
            }else if(type_ == "req_event_delete") {
                response = handle_delete_schedule(data);
            }else if(type_ == "req_dept_create"){
                response = handle_make_dept(data);               
            }else if(type_ == "req_dept_read"){
                response = handle_read_dept(data);
            }else if(type_ == "req_dept_update"){
                response = handle_update_dept(data);
            }else if(type_ == "req_dept_delete"){
                response = handle_delete_dept(data);
            }


            //C++에서 JSON 데이터를 문자열로 직렬화(serialize) 하는 코드입니다.
            string response_str = response.dump();
            //클라이언트에  send 함수로 응답을 한다.
            send(client_socket, response_str.c_str(), response_str.size(), 0);
            //shutdown이 클라이언트에서 서버의 응답이 끝났다는 신호이다.
            shutdown(client_socket, SHUT_WR);
            
            cout<<"클라이언트로 응답했다. " << response_str<<endl;
        } catch(const exception& e){
            cerr <<"json 파싱 오류 : " << e.what() <<endl;
        }
        
    }
    close(client_socket);
}  



json handle_read_schedule(){
    
    
    MYSQL* conn = connect_db();
    
    if (conn == nullptr) {
       cout<< "db 커넥션 오류 >>line 91";
    }
   
    
    string query = "select * from EVENTS ORDER BY START_DATE ASC limit 5;";

    //db로부터 받아온 내용을 json에 담아서 클라이언트로 전송 

    if(mysql_query(conn, query.c_str())!=0){
        cerr << "쿼리 실패: " <<mysql_error(conn) << endl;
        exit(1);
    }

    MYSQL_RES* result = mysql_store_result(conn);

    if(!result){
        cerr <<"결과 없음 또는 에러 : " << mysql_error(conn) << endl;
        exit(1);
    }
    
    int num_fields= mysql_num_fields(result);

    json json_result = json::array(); //전체 결과를 배열로
    
    MYSQL_ROW row;
    while((row = mysql_fetch_row(result))){
        
        //여기서 각 값들에 대해 json으로 넣어야 한다. 단! s_date 를 기준으로 
        
//string query = "INSERT INTO EVENTS (START_DATE, END_DATE, EVENT_NAME, GROUP_ID, DEPT_ID, DESCRIPTION) VALUES ('" 
        json data;
        data["EVENT_ID"]          = row[0] ? atoi(row[0]) : 0;
        data["GROUP_ID"]          = row[1] ? atoi(row[1]) : 0;
        data["DEPT_ID"]           = row[2] ? atoi(row[2]) : 0;
        data["EVENT_NAME"]        = row[3] ? row[3] : "";
        data["START_DATE"]        = row[4] ? row[4] : "";
        data["END_DATE"]          = row[5] ? row[5] : "";
        data["DESCRIPTION"]       = row[6] ? row[6] : "";

        json_result.push_back(data);        
        
    }

    cout<< json_result << endl;

    mysql_free_result(result);

    mysql_close(conn);
    
    return json_result;
}

/**
 * 스케쥴을 서버에 insert
 */

json handle_make_schedule(const json& data){
    json result;
    if (!data.contains("START_DATE") || !data.contains("END_DATE") || !data.contains("EVENT_NAME")  ) {
        result["status"] = "error";
        result["message"]= "필수 필드 누락";
        return result;
    }



    //삼항연산자로 존재하는지 확인후 담는다
    string s_date = data.contains("START_DATE")? data["START_DATE"].get<string>() : "";
    string e_date =  data.contains("END_DATE")? data["END_DATE"].get<string>() : "";
    string event_name =  data.contains("EVENT_NAME")? data["EVENT_NAME"].get<string>() : "";    
    string event_detail =  data.contains("DESCRIPTION")? data["DESCRIPTION"].get<string>() : "";    
    int group_id =  data.contains("GROUP_ID")? data["GROUP_ID"].get<int>() : 0;    
    int dept_id =  data.contains("DEPT_ID")? data["DEPT_ID"].get<int>() : 0;    


    MYSQL* conn = connect_db();
    if (conn == nullptr) {
        result["status"] = "error";
        result["message"] = "DB 연결 실패";
        return result;
    }

    string query = "INSERT INTO EVENTS (START_DATE, END_DATE, EVENT_NAME, GROUP_ID, DEPT_ID, DESCRIPTION) VALUES ('" 
    + s_date + "', '" 
    + e_date + "', '" 
    + event_name + "', " 
    + std::to_string(group_id) + ", "   
    + std::to_string(dept_id) + ", '"  
    + event_detail+ "')";

    cout << query << endl;

    if(mysql_query(conn, query.c_str())!=0){
        cerr << "쿼리 실패: " << mysql_error(conn) <<endl;
        result["status"]= "error";
        result["message"] = "DB 쿼리 실패: " +string(mysql_error(conn));
        mysql_close(conn);
        return result;
    }

    result["status"] = "success";
    result["message"] = "일정이 성공적으로 등록되었습니다.";

    
    mysql_close(conn);
    
    return result;   
    
}

json handle_delete_dept(const json& data){
    json result;

    int dept_id = data.contains("DEPT_ID") ? data["DEPT_ID"].get<int>():0;

    MYSQL* conn = connect_db();
    if (conn == nullptr) {
        result["status"] = "error";
        result["message"] = "DB 연결 실패";
        return result;
    }

    string query = "delete from DEPT where DEPT_ID = " + to_string(dept_id); 

    cout << query << endl;

    if(mysql_query(conn, query.c_str())!=0){
        cerr << "쿼리 실패: " << mysql_error(conn) <<endl;
        result["status"]= "error";
        result["message"] = "DB 쿼리 실패: " +string(mysql_error(conn));
        mysql_close(conn);
        return result;
    }


    result["status"] = "success";
    result["message"] = "부서가 성공적으로 삭제되었습니다.";    
    mysql_close(conn);    
    return result;  


}

json handle_delete_schedule(const json& data){
    json result;

    int event_id = data.contains("EVENT_ID") ? data["EVENT_ID"].get<int>():0;

    MYSQL* conn = connect_db();
    if (conn == nullptr) {
        result["status"] = "error";
        result["message"] = "DB 연결 실패";
        return result;
    }

    string query = "delete from EVENTS where EVENT_ID = " + to_string(event_id); 

    cout << query << endl;

    if(mysql_query(conn, query.c_str())!=0){
        cerr << "쿼리 실패: " << mysql_error(conn) <<endl;
        result["status"]= "error";
        result["message"] = "DB 쿼리 실패: " +string(mysql_error(conn));
        mysql_close(conn);
        return result;
    }

    result["status"] = "success";
    result["message"] = "일정이 성공적으로 삭제되었습니다.";    
    mysql_close(conn);    
    return result;  
    
}

json handle_update_schedule(const json& data)
{

    json result;
    if (!data.contains("START_DATE") || !data.contains("END_DATE") || !data.contains("EVENT_NAME")  ) {
        result["status"] = "error";
        result["message"]= "필수 필드 누락";
        return result;
    }

    std::cout<< data << endl;


    //삼항연산자로 존재하는지 확인후 담는다
    string s_date = data.contains("START_DATE")? data["START_DATE"].get<string>() : "";
    string e_date =  data.contains("END_DATE")? data["END_DATE"].get<string>() : "";
    string event_name =  data.contains("EVENT_NAME")? data["EVENT_NAME"].get<string>() : "";    
    string event_detail =  data.contains("DESCRIPTION")? data["DESCRIPTION"].get<string>() : "";    
    // string event_organization =  data.contains("org_name")? data["org_name"].get<string>() : "";    
    int dept_id =  data.contains("DEPT_ID")? data["DEPT_ID"].get<int>() : 0;    
    int group_id = data.contains("GROUP_ID") ? data["GROUP_ID"].get<int>():0;
    int event_id = data.contains("EVENT_ID") ? data["EVENT_ID"].get<int>():0;

    MYSQL* conn = connect_db();
    if (conn == nullptr) {
        result["status"] = "error";
        result["message"] = "DB 연결 실패";
        return result;
    }

   // string query = "INSERT INTO EVENTS (START_DATE, END_DATE, EVENT_NAME, GROUP_ID, DEPT_ID, DESCRIPTION) VALUES ('" 
    string query = "UPDATE EVENTS SET "
               "START_DATE = '" + s_date + "', "
               "END_DATE = '" + e_date + "', "
               "EVENT_NAME = '" + event_name + "', "
               "GROUP_ID = " + to_string(group_id) + ", "
               "DEPT_ID = '" + to_string(dept_id) + "', "
               "DESCRIPTION = '" + event_detail + "' "
               "WHERE EVENT_ID = " + to_string(event_id);

    cout << query << endl;

    if(mysql_query(conn, query.c_str())!=0){
        cerr << "쿼리 실패: " << mysql_error(conn) <<endl;
        result["status"]= "error";
        result["message"] = "DB 쿼리 실패: " +string(mysql_error(conn));
        mysql_close(conn);
        return result;
    }

    result["status"] = "success";
    result["message"] = "일정이 성공적으로 등록되었습니다.";    
    mysql_close(conn);    
    return result;  
}



int main(){
    int server_fd, new_socket;
    struct sockaddr_in address{};    
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0))==0) {
        perror("socket failed"); return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed"); return 1;
    }

    if(listen(server_fd, 3)<0){
        perror("listen"); return 1;
    }

    cout <<"서버 대기중 ... 포트 " <<PORT <<endl;

    while(true){
        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if(new_socket <0){
            perror("accept"); continue;
        }

        cout <<"클라이언트 연결됨!"<< endl;
        thread t(handle_client, new_socket);
        t.detach();
        
    }
    close(server_fd);
    return 0;

}