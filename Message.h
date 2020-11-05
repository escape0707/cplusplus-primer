#pragma once

#include <set>
#include <string>

class Folder;

class Message {
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);

 public:
  Message();
  explicit Message(const std::string &contents);
  Message(const Message &other);
  Message(Message &&other);
  Message &operator=(const Message &rhs);
  Message &operator=(Message &&rhs);
  ~Message();
  void save(Folder &folder);
  void remove(Folder &folder);

 private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_folders();
  void remove_from_folders();
  void rmFolder(Folder *folder);
  void move_folders(Message *m);
};
