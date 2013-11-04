#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <unordered_set>
#include "Message.h"

class Message;

class Folder
{
public:
	Folder(const std::string str=""): folderName(str) {}
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();

	void addMsg(Message*);
	void remMsg(Message*);
	void print() const; // for test
	std::string getFldrName() const; // for test

private:
	std::string folderName;
	//store Message pointers under the folder
	std::unordered_set<Message*> messages;

	void putFldrInMsgSet(const std::unordered_set<Message*>&);
	void removeFldrFromMsgSet();
};

#endif // FOLDER_H
