#include <iostream>
#include <string>
using namespace std;

class AuthenticationResult {
private:
    const bool _c_is_authenticated;
    const string _c_username;

public:
    AuthenticationResult(const bool c_is_authenticated, const string c_username = "unauthenticated_user")
    : _c_is_authenticated(c_is_authenticated), _c_username(c_username){}

    const bool get_is_authenticated() const{
        return _c_is_authenticated;
    }

    const string get_username() const{
        return _c_username;
    }
};

class IAuthenticationProcedure{
public:
    virtual AuthenticationResult authenticate() = 0;
};

class Client{
private:
    IAuthenticationProcedure* _authentication_procedure;

public:
    void set_authentication_procedure(IAuthenticationProcedure* authentication_procedure){
        _authentication_procedure = authentication_procedure;
    }

    void execute() {
        if (_authentication_procedure) {
            const AuthenticationResult result = _authentication_procedure->authenticate();
            if (result.get_is_authenticated()) {
                cout << "Das Programm wird ausgeführt für " << result.get_username() << "." << endl;
            } else {
                cout << "Das Programm konnte nicht ausgeführt werden." << endl;
            }
        }
    }
};

class MockAuthentication : public IAuthenticationProcedure {
public:
    AuthenticationResult authenticate() override {
        return AuthenticationResult(true, "Default");
    }
};

class UsernamePassword : public IAuthenticationProcedure{
public:
    AuthenticationResult authenticate() override {
        string username;
        string password;

        cout << "Username: ";
        cin >> username;
        cout << endl;

        cout << "Password: ";
        cin >> password;
        cout << endl;

        if(username == password){
            return AuthenticationResult(true, username );
        }
        else{
            return AuthenticationResult(false, username);
        }
    }
};

class Certificate : public IAuthenticationProcedure{
public:
    AuthenticationResult authenticate() override {
        string certificate;
        cout << "Zertifikatsaussteller: " << endl;
        cin >> certificate;
        if(certificate == "hs-esslingen"){
            cout << certificate << endl;}

        if (certificate == "hs-esslingen") {
            return AuthenticationResult(true, "certificate.owner");
        } else {
            return AuthenticationResult(false, "Certificate: Authentication failed");
        }
    }
};



int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über das Authentifizierungsverfahren Mock Authentication" << endl;
    IAuthenticationProcedure* mock_authentication = new MockAuthentication();
    client.set_authentication_procedure(mock_authentication);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Username Password" << endl;
    IAuthenticationProcedure* username_password = new UsernamePassword();
    client.set_authentication_procedure(username_password);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Zertifikat" << endl;
    IAuthenticationProcedure* certificate = new Certificate();
    client.set_authentication_procedure(certificate);
    client.execute();
    return 0;
}


