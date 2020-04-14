#pragma once
#include <string>
#include <vector>

using namespace std;

typedef enum gender {
	Man,
	Woman
} gender_t;

class Person {

public:
	Person();
	Person(string name, int age, gender_t gender);
	~Person();

	string getName() const;
	int getAge() const;
	gender_t getGender() const;
	Person* getObject() const;
	vector<Person*> getFriends() const;
	string description() const;        //ÃèÊö

	void getMarried(Person& object);   //½á»é
	void divorce();                    //Àë»é
	void addFriend(Person& aFriend);   //Ìí¼ÓºÃÓÑ
	void breakFriend(Person& bFriend); //É¾³ıºÃÓÑ

private:
	string name;
	int age;
	gender_t gender;
	Person* object = NULL;
	vector<Person*> friends;
};