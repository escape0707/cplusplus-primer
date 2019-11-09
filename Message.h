#ifndef MESSAGE_H
#define MESSAGE_H

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
  Message &operator=(const Message &rhs);
  ~Message();
  void save(Folder &folder);
  void remove(Folder &folder);

 private:
  std::string contents;
  std::set<Folder *> folders;
  void add_to_Folders_of(const Message &other);
  void remove_from_Folders();
  void addFolder(Folder *folder);
  void rmFolder(Folder *folder);
};

#endif
