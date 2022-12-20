#include <iostream>

using namespace std;

struct Authentication
{
	Authentication* m_next{ nullptr };

	virtual bool authenticate() = 0;
	void next_authentication(Authentication* nextAuth) { m_next = nextAuth; }
};

struct UserName : Authentication
{
	string m_name;

	UserName(string name) : m_name(name) {}
	bool is_valid_user_name() { return true; }
	bool authenticate() {
		if (!is_valid_user_name()) {
			cout << "Invalid user name" << endl;
			return false;
		}
		else if (m_next) return m_next->authenticate();
		return true;
	}
};

struct Password : Authentication
{
	string m_password;

	Password(string password) : m_password(password) {}
	bool is_valid_password() { return true; }
	bool authenticate() {
		if (!is_valid_password()) {
			cout << "Invalid password" << endl;
			return false;
		}
		else if (m_next) return m_next->authenticate();
		return true;
	}
};

int main() {
	Authentication* login{ new UserName("John") };
	login->next_authentication(new Password("password"));
	login->authenticate();
	return 0;
}