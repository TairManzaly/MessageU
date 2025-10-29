#include <boost/asio.hpp>
#include <iostream>
#include <string>
using namespace std;
using boost::asio::ip::tcp;



int Register(){
    
//header: client ID 16 Version 1 Cose 2 Payload syze 4 
// payload: Name - 255 byts Public key: 160 byts
    // uint clientID;
    // uint8_t version = 1;
    // uint1
}

int clientList(){
    uint16_t code = htons(120);
    uint32_t payload_size = htonl(0);

}

int publicKey(){

}

int waitingMessage(){

}
int textMessage(){

}
int symetricKeyRequest(){

}
int Exit(){

}

int userMenu(){
    cout<<" MessageU client at your service.\n";
    cout << "110) Register\n";
    cout << "120) Request for clients list\n";
    cout << "130) Request for public key\n";
    cout << "140) Request for waiting messages\n";
    cout << "150) Send a text message\n";
    cout << "151) Send a request for symmetric key\n";
    cout << "152) Send your symemetric key\n";
    cout << "0) Exit client\n";
    cout << "?";
    string choice;
    cin>> choice;
    return stoi(choice);
    

}

int requestChoice(int i){
   switch (i)
   {
   case 110:
    /* code */
    break;
    case 120:
    break;
    case 130:
    break;
        case 140:
    break;

        case 150:
    break;

        case 151:
    break;

        case 152:
    break;


   
   case 0:
    break;
    
   }
   return 0;
}
int main(int argc, char const *argv[])
{
    char address[] = "127.0.0.1";
char port[] = "1234";
try
{
boost::asio::io_context io_context;
tcp::socket s(io_context);
tcp::resolver resolver(io_context);

boost::asio::connect(s, resolver.resolve(address,port));
cout << "Connect to server";
const int max_length = 1024;
char request[max_length];

while (true)
{
    int choice = userMenu();
    cout<< "you chose";
    // std::cin.getline(request,max_length);
    // boost::asio::write(s,boost::asio::buffer(request,max_length));
    
    requestChoice(choice);
}}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}



    return 0;
}
