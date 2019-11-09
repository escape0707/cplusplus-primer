#include <algorithm>

#include "Folder.h"
#include "Message.h"

Message::Message() = default;
Message::Message(const std::string &contents) : contents(contents) {}

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.rmMsg(this);
}

void Message::add_to_Folders_of(const Message &other) {
  for (Folder *f : other.folders) {
    f->addMsg(this);
  }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folders_of(m);
}

void Message::remove_from_Folders() {
  for (Folder *f : folders) {
    f->rmMsg(this);
  }
}

Message::~Message() {
  remove_from_Folders();
}

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders_of(rhs);
  return *this;
}

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  lhs.remove_from_Folders();
  rhs.remove_from_Folders();
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  lhs.add_to_Folders_of(lhs);
  rhs.add_to_Folders_of(rhs);
}

void Message::addFolder(Folder *f) {
  folders.insert(f);
}

void Message::rmFolder(Folder *f) {
  folders.erase(f);
}
