#include "Message.h"
#include <iostream>

using namespace std;

Message::Message(const Message &other):
	contents(other.contents), folders(other.folders)
{
	putMsgInFolders(other.folders);
}

Message& Message::operator=(const Message &other)
{
	if (this != &other)
	{
		// remove associated message pointers in folders
		removeMsgFromFolders();

		// copy message
		contents = other.contents;
		folders = other.folders;

		// let folders contain the pointer to this message
		putMsgInFolders(other.folders);
	}

	return *this;
}

Message::~Message()
{
	removeMsgFromFolders();
}

void Message::addFldr(Folder *fptr)
{
	folders.insert(fptr);
}

void Message::remFldr(Folder *fptr)
{
	folders.erase(fptr);
}

void Message::save(Folder &folder)
{
	folder.addMsg(this);
	folders.insert(&folder);
}

void Message::remove(Folder &folder)
{
	folder.remMsg(this);
	folders.erase(&folder);
}

void Message::print() const
{
	cout << "Message contents: " << contents << endl;
	for (auto itr=folders.begin(); itr!=folders.end(); itr++)
	{
		cout << "\t" << (*itr)->getFldrName() << endl;
	}
}

string Message::getContents() const
{
	return contents;
}

void Message::putMsgInFolders(const unordered_set<Folder*> &other)
{
	for (auto itr=other.cbegin(); itr!=other.cend(); itr++)
	{
		(*itr)->addMsg(this);
	}
}

void Message::removeMsgFromFolders()
{
	for (auto itr=folders.begin(); itr!=folders.end(); itr++)
	{
		(*itr)->remMsg(this);
	}

	folders.clear();
}
