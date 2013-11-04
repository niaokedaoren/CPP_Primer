#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <unordered_set>
#include "Folder.h"

class Folder;

class Message
{
public:
	Message(const std::string &str = ""): contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	
	void addFldr(Folder*);
	void remFldr(Folder*);
	void save(Folder&);
	void remove(Folder&);
	void print() const; // for test
	std::string getContents() const; // for test

private:
	// message content
	std::string contents;    
	// store folder pointers which include this message
	std::unordered_set<Folder*> folders; 

	void putMsgInFolders(const std::unordered_set<Folder*>&);
	void removeMsgFromFolders();
};

#endif // MESSAGE_H
