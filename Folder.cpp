#include "Folder.h"

#include "Message.h"

Folder::Folder() = default;

Folder::~Folder() {
  for (Message *pmsg : messages) {
    pmsg->rmFolder(this);
  }
}

void Folder::addMsg(Message *pmsg) {
  messages.insert(pmsg);
}

void Folder::rmMsg(Message *pmsg) {
  messages.erase(pmsg);
}
