#include "Message.h"

#include <algorithm>

#include "Folder.h"

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

void Message::add_to_folders() {
  for (Folder *f : folders) {
    f->addMsg(this);
  }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_folders();
}

Message::Message(Message &&m) : contents(std::move(m.contents)) {
  move_folders(&m);
}

void Message::remove_from_folders() {
  for (Folder *f : folders) {
    f->rmMsg(this);
  }
}

Message::~Message() {
  remove_from_folders();
}

Message &Message::operator=(const Message &rhs) {
  remove_from_folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_folders();
  return *this;
}

Message &Message::operator=(Message &&rhs) {
  remove_from_folders();
  contents = std::move(rhs.contents);
  move_folders(&rhs);
  return *this;
}

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  lhs.remove_from_folders();
  rhs.remove_from_folders();
  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);
  lhs.add_to_folders();
  rhs.add_to_folders();
}

void Message::rmFolder(Folder *f) {
  folders.erase(f);
}

void Message::move_folders(Message *m) {
  // remove_from_folders() is done before this function
  m->remove_from_folders();
  folders = move(m->folders);
  m->folders.clear();
  add_to_folders();
}
