#include "Folder.h"
#include "Message.h"

Folder::Folder() = default;

void Folder::addMsg(Message *pmsg) {
  messages.insert(pmsg);
}

void Folder::rmMsg(Message *pmsg) {
  messages.erase(pmsg);
}

Folder::~Folder() {
  for (Message *pmsg : messages) {
    // when you find you need something like rmMsg() and alse make Folder a
    // friend class of Message, you should consider merge these classes or
    // create a base class for them.
    pmsg->rmFolder(this);
  }
}
