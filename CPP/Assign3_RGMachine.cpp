#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <utility>

#define LEFT_LEANING(x) static_cast<int>((x) == 1)
#define RIGHT_LEANING(x) static_cast<int>((x) == -1)
#define BALANCED(x) ((x) == 0)

#define LEFT_HEAVY_UNBALANCED 2
#define RIGHT_HEAVY_UNBALANCED -2

// Balancing mode, to optimize size.

enum class balancing_factor_t : bool {
  caching = true,
  non_caching = false,
};

// This is the base of our AVLNode class.
// Default constructor is protected to only support inheritance use case.

template <class, balancing_factor_t>
class AVLNode;

template <class, balancing_factor_t>
class AVLTree;

// This is base implementation of balancing factor method.

class balancing_factor_base {
  template <class T, balancing_factor_t mode>
  int getMaxHeightOfSubtree(AVLNode<T, mode> *node) const {
    if (node == nullptr) {
      return 0;
    } else {
      return 1 + std::max(getMaxHeightOfSubtree(node->left),
                          getMaxHeightOfSubtree(node->right));
    }
  }

 public:
  template <class T, balancing_factor_t mode>
  int getBalancingFactor(const AVLNode<T, mode> &self) const {
    return getMaxHeightOfSubtree(self.left) - getMaxHeightOfSubtree(self.right);
  }
};

template <class, class, balancing_factor_t>
struct balancing_factor_impl;

template <class T, class Derived>
struct balancing_factor_impl<T, Derived, balancing_factor_t::caching>
    : balancing_factor_base {
 protected:
  unsigned node_balancing_factor = UINT_MAX;

 public:
  int getBalancingFactor() {
    if (node_balancing_factor == UINT_MAX) {
      node_balancing_factor = balancing_factor_base::getBalancingFactor(
          static_cast<Derived &>(*this));
    }
    return node_balancing_factor;
  }
  void updateBalancingFactor() {
    node_balancing_factor = balancing_factor_base::getBalancingFactor(
        static_cast<Derived &>(*this));
  }
};

template <class T, class Derived>
struct balancing_factor_impl<T, Derived, balancing_factor_t::non_caching>
    : balancing_factor_base {
  int getBalancingFactor() {
    return balancing_factor_base::getBalancingFactor(
        static_cast<Derived &>(*this));
  }
  void updateBalancingFactor() {}
};

template <class T, balancing_factor_t mode = balancing_factor_t::caching>
class AVLNode : public balancing_factor_impl<T, AVLNode<T, mode>, mode> {
  T data;
  AVLNode *parent;
  AVLNode *left;
  AVLNode *right;

  friend class AVLTree<T, mode>;
  friend class balancing_factor_base;

 public:
  AVLNode(T data) : data(data) {}
  AVLNode(T data, AVLNode *parent = nullptr, AVLNode *left = nullptr,
          AVLNode *right = nullptr)
      : data(data), parent(parent), left(left), right(right) {}
};

template <class T, balancing_factor_t mode = balancing_factor_t::caching>
class AVLTree {
  // static_assert(std::is_swappable<T>::value,
  //"Type must be swappable with itself.");
  static_assert(std::is_reference<T>::value == false,
                "Type cannot be reference.");

  using node_type = AVLNode<T, mode>;
  node_type *root = nullptr;

  enum class traversal_t {
    pre_order,
    in_order,
    post_order,
  };

  std::pair<node_type **, node_type *> getPointerPairForInsertion(
      const T &value) {
    node_type *p = root;
    if (p == nullptr) {
      return {&root, nullptr};
    }
    for (;;) {
      if (std::less<T>{}(value, p->data)) {
        if (p->left != nullptr) {
          p = static_cast<node_type *>(p->left);
        } else {
          return {&p->left, p};
        }
      } else if (std::greater<T>{}(value, p->data)) {
        if (p->right != nullptr) {
          p = static_cast<node_type *>(p->right);
        } else {
          return {&p->right, p};
        }
      } else {
        return {nullptr, nullptr};
      }
    }
  }
  void rotateLeft(node_type *ptr) {
    //    A                B
    //     \              / \
    //      B      ->    A   D
    //     / \            \
    //    C   D            C
    if (ptr->parent) {
      if (ptr->parent->left == ptr) {
        ptr->parent->left = ptr->right;
      } else {
        ptr->parent->right = ptr->right;
      }
    } else {
      root = ptr->right;
    }
    ptr->right->parent = ptr->parent;
    ptr->parent = ptr->right;
    auto &x = ptr->right->left;
    ptr->right = x;
    x = ptr;
  }
  void rotateRight(node_type *ptr) {
    //      A             B
    //     /             / \
    //    B        ->   C   A
    //   / \               /
    //  C   D             D
    if (ptr->parent) {
      if (ptr->parent->left == ptr) {
        ptr->parent->left = ptr->left;
      } else {
        ptr->parent->right = ptr->left;
      }
    } else {
      root = ptr->left;
    }
    ptr->left->parent = ptr->parent;
    ptr->parent = ptr->left;
    auto &x = ptr->left->right;
    ptr->left = x;
    x = ptr;
  }
  node_type *getRightMostNode(node_type *node) {
    if (node->right) {
      return getRightMostNode(node->right);
    }
    return node;
  }
  node_type *findInorderPredecessor(node_type *node) {
    // Only valid for two child case
    assert(node->left != nullptr && node->right != nullptr);
    return getRightMostNode(node->left);
  }
  void deleteNodeAt(node_type *node, bool rec = false) {
    auto child_case = !!node->left + !!node->right;
    if (rec) {
      assert(child_case != 2);
    }
    // guard deletion of node when swapping
    bool guard = false;
    switch (child_case) {
      case 0: {
        if (node->parent) {
          if (node->parent->left == node) {
            node->parent->left = nullptr;
          } else {
            node->parent->right = nullptr;
          }
        } else {
          assert(node == root);
          root = nullptr;
        }
      } break;
      case 1: {
        auto child = node->left ? node->left : node->right;
        if (node->parent) {
          if (node->parent->left == node) {
            node->parent->left = child;
          } else {
            node->parent->right = child;
          }
        } else {
          assert(node == root);
          root = child;
        }
        child->parent = node->parent;
      } break;
      case 2: {
        auto predecessor = findInorderPredecessor(node);
        assert(predecessor->parent != nullptr);
        // Right subtree is not present, left may be
        assert(predecessor->right == nullptr);
        // We need to unlink predecessor now, but also handle its cases
        using std::swap;
        swap(node->data, predecessor->data);
        // Will never recurse again after this call
        deleteNodeAt(predecessor, true);
        guard = true;
      } break;
      default:
        __builtin_unreachable();
    }
    auto parent = node->parent;
    if (!guard) {
      if (node->left) assert(node->left->parent != node);
      if (node->right) assert(node->right->parent != node);
      delete node;
    }
    rebalanceTreeGoingUp(parent ? parent : root);
  }
  void rebalanceSubtreeAt(node_type *ptr) {
    ptr->updateBalancingFactor();
    assert(ptr);
    auto bf_self = ptr->getBalancingFactor();
    switch (bf_self) {
      case LEFT_HEAVY_UNBALANCED: {
        auto bf_left = ptr->left->getBalancingFactor();
        assert(BALANCED(bf_left) == false);
        switch (LEFT_LEANING(bf_left)) {
          case true:
            rotateRight(ptr);
            ptr->updateBalancingFactor();
            break;
          case false:
            rotateLeft(ptr->left);
            ptr->left->updateBalancingFactor();
            rotateRight(ptr);
            ptr->updateBalancingFactor();
            break;
          default:
            __builtin_unreachable();
        }
        break;
      }
      case RIGHT_HEAVY_UNBALANCED: {
        auto bf_right = ptr->right->getBalancingFactor();
        assert(BALANCED(bf_right) == false);
        switch (RIGHT_LEANING(bf_right)) {
          case true:
            rotateLeft(ptr);
            ptr->updateBalancingFactor();
            break;
          case false:
            rotateRight(ptr->right);
            ptr->right->updateBalancingFactor();
            rotateLeft(ptr);
            ptr->updateBalancingFactor();
            break;
          default:
            __builtin_unreachable();
        }
        break;
      }
      case -1:
      case 0:
      case 1:
        break;
      default:
        __builtin_unreachable();
    }
  }
  void rebalanceTreeGoingUp(node_type *node) {
    while (node != nullptr) {
      rebalanceSubtreeAt(node);
      node = node->parent;
    }
  }
  template <class Callable>
  void visitNode(AVLNode<T, mode> &node, Callable &&f) {
    std::invoke(f, node.data);
  }
  template <class Callable>
  void traverseTree(AVLNode<T, mode> *root, Callable &&f, traversal_t order) {
    if (root == nullptr) {
      return;
    }
    if (order == traversal_t::pre_order) {
      visitNode(*root, f);
    }
    traverseTree(root->left, f, order);
    if (order == traversal_t::in_order) {
      visitNode(*root, f);
    }
    traverseTree(root->right, f, order);
    if (order == traversal_t::post_order) {
      visitNode(*root, f);
    }
  }
  void freeChildrenRecursive(node_type *node) {
    if (node->left) freeChildrenRecursive(node->left);
    if (node->right) freeChildrenRecursive(node->right);
    delete node;
  }

 public:
  bool insert(const T &value) {
    auto p = getPointerPairForInsertion(value);
    auto ptr = p.first;
    auto parent = p.second;
    if (ptr == nullptr) {
      return true;
    } else {
      assert(*ptr == nullptr);
      *ptr = new node_type{value, parent, nullptr, nullptr};
      rebalanceTreeGoingUp(*ptr);
      return true;
    }
  }
  bool erase(const T &value) {
    auto p = root;
    for (; p;) {
      if (std::less<T>{}(value, p->data)) {
        p = p->left;
      } else if (std::greater<T>{}(value, p->data)) {
        p = p->right;
      } else {
        deleteNodeAt(p);
        return true;
      }
    }
    return false;
  }
  template <class Callable>
  void traversePreOrder(Callable &&f) {
    traverseTree(root, std::forward<Callable>(f), traversal_t::pre_order);
  }
  template <class Callable>
  void traverseInOrder(Callable &&f) {
    traverseTree(root, std::forward<Callable>(f), traversal_t::in_order);
  }
  template <class Callable>
  void traversePostOrder(Callable &&f) {
    traverseTree(root, std::forward<Callable>(f), traversal_t::post_order);
  }
  ~AVLTree() noexcept {
    if (root) freeChildrenRecursive(root);
  }
};

// DLL

template <class T>
struct DoublyLinkedListNode {
  T data;
  DoublyLinkedListNode *prev;
  DoublyLinkedListNode *next;
  void swap(DoublyLinkedListNode &that) {
    using std::swap;
    swap(data, that.data);
  }
};

template <class T>
inline static DoublyLinkedListNode<T> right_sentinel_v;

template <class T>
class DoublyLinkedList {
  using Node = DoublyLinkedListNode<T>;
  Node *head = nullptr;
  Node *tail = nullptr;

  struct DoublyLinkedListIterator
      : public std::iterator<std::bidirectional_iterator_tag, T> {
#define right_sentinel right_sentinel_v<T>

    DoublyLinkedListNode<T> *ptr = nullptr;
    DoublyLinkedList<T> *ll = nullptr;

    DoublyLinkedListIterator(DoublyLinkedListNode<T> *ptr,
                             DoublyLinkedList<T> *ll)
        : ptr(ptr), ll(ll) {}
    T &operator*() {
      if (ptr)
        return ptr->data;
      else
        throw std::runtime_error("Dereferencing invalid iterator.");
    }
    // Make operator-> conditional on whether T is a class/struct or not
    template <class U = T, class = std::enable_if_t<std::is_class_v<U>>>
    T *operator->() {
      return &ptr->data;
    }
    DoublyLinkedListIterator operator++() {
      if (ptr && ptr != &right_sentinel) {
        ptr = ptr->next ? ptr->next : &right_sentinel;
      } else if (ptr == &right_sentinel)
        throw std::runtime_error("Trying to increment end iterator");
      return *this;
    }
    DoublyLinkedListIterator operator--() {
      if (ptr == &right_sentinel) {
        ptr = ll->tail;
      } else if (ptr && ptr->prev) {
        ptr = ptr->prev;
      } else
        throw std::runtime_error("Trying to decrement begin iterator");
      return *this;
    }
    DoublyLinkedListIterator operator++(int) {
      auto ret = *this;
      if (ptr && ptr != &right_sentinel) {
        ptr = ptr->next ? ptr->next : &right_sentinel;
      } else if (ptr == &right_sentinel) {
        throw std::runtime_error("Trying to increment end iterator");
      }
      return ret;
    }
    DoublyLinkedListIterator operator--(int) {
      auto ret = *this;
      if (ptr == &right_sentinel) {
        ptr = ll->tail;
      } else if (ptr && ptr->prev) {
        ptr = ptr->prev;
      } else
        throw std::runtime_error("Trying to decrement begin iterator");
      return ret;
    }
    bool operator!=(const DoublyLinkedListIterator &that) {
      assert(ll == that.ll);
      return ptr != that.ptr;
    }
    bool operator==(const DoublyLinkedListIterator &that) {
      assert(ll == that.ll);
      return ptr == that.ptr;
    }
  };

 public:
  using iterator = DoublyLinkedListIterator;
  using reference = T &;

  void pushBack(const T &value) {
    if (head == nullptr) {
      assert(tail == nullptr);
      head = tail = new Node{value, nullptr, nullptr};
    } else {
      assert(head != nullptr);
      assert(tail != nullptr);
      assert(tail->next == nullptr);

      tail->next = new Node{value, tail, nullptr};
      tail = tail->next;
    }
  }
  void pushFront(const T &value) {
    if (head == nullptr) {
      assert(tail == nullptr);
      head = tail = new Node{value, nullptr, nullptr};
    } else {
      auto cur_head = head;
      head = new Node{value, nullptr, cur_head};
      cur_head->prev = head;
    }
  }
  void popBack() {
    if (tail) {
      auto tail_prev = tail->prev;
      auto remove = tail;
      tail = tail_prev;
      if (tail) {
        assert(tail->next == remove);
        tail->next = nullptr;
      }
      delete remove;
      if (head == remove) {
        head = tail = nullptr;
      }
    } else {
      assert(head == nullptr);
      throw std::runtime_error("List is empty");
    }
  }
  void popFront() {
    if (head) {
      auto head_next = head->next;
      auto remove = head;
      head = head_next;
      if (head_next) {
        assert(head->prev == remove);
        head->prev = nullptr;
      }
      delete remove;
      if (tail == remove) {
        tail = head = nullptr;
      }
    } else {
      assert(tail == nullptr);
      throw std::runtime_error("List is empty");
    }
  }
  reference getFront() {
    if (head)
      return head->data;
    else
      throw std::runtime_error("List is empty");
  }
  reference getBack() {
    if (tail)
      return tail->data;
    else
      throw std::runtime_error("List is empty");
  }
  void insertAfter(iterator it, const T &value) {
    assert(it.ptr != &right_sentinel_v<T>);
    assert(it.ll == this);
    auto node = it.ptr;
    auto node_next = node->next;
    node->next = new Node{value, node, node->next};
    if (node_next) {
      node_next->prev = node->next;
    }
    if (node == tail) {
      tail = node->next;
    }
  }
  Node *getHeadNodePtr() { return head; }
  Node *getTailNodePtr() { return tail; }

  iterator begin() { return {head, this}; }
  iterator end() { return {&right_sentinel, this}; }
};

// Free Functions

template <class T>
void insertSorted(typename DoublyLinkedList<T>::iterator begin,
                  typename DoublyLinkedList<T>::iterator end, const T &value) {
#if 0
  for (auto it = begin; it != end; ++it) {
    if (std::less<T>{}(value, *it)) {
      continue;
    } else {
      it.ll->insertAfter(it, value);
    }
  }
#endif
  begin.ll->pushBack(value);
  quickSort(begin, end);
}

template <class BidirIt>
void quickSort(BidirIt begin, BidirIt end) {
  auto num = std::distance(begin, end);
  switch (num) {
    case 0:
    case 1:
      return;
    case 2:
      if (std::greater<typename BidirIt::value_type>{}(*begin,
                                                       *std::next(begin))) {
        using std::swap;
        swap(*begin, *std::next(begin));
      }
      return;
    default:
      break;
  }
  auto it = begin;
  std::advance(it, rand() % num);
  auto next = std::partition(begin, end, [val = *it](auto i) mutable {
    return std::less<typename BidirIt::value_type>{}(i, val);
  });
  quickSort(begin, next);
  quickSort(next, end);
}

template <class T>
class Stack {
  DoublyLinkedList<T> list;

 public:
  void pushStack(const T &value) { list.pushBack(value); }
  void popStack() { list.popBack(); }
  T &getTopOfStack() { return list.getBack(); }
  bool isEmpty() { return list.getHeadNodePtr() == nullptr; }
};

template <class T>
class DEQueue {
  DoublyLinkedList<T> list;

 public:
  void pushFront(const T &value) { list.pushFront(value); }
  void popFront() { list.popFront(); }
  void pushBack(const T &value) { list.pushBack(value); }
  void popBack() { list.popBack(); }
  T &getFront() { return list.getFront(); }
  T &getBack() { return list.getBack(); }
  bool isEmpty() { return list.getHeadNodePtr() == nullptr; }
};

// Main

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto stringPrepare(std::string str, const char *delim) {
  std::vector<std::string> v;
  char *s = str.data();
  while ((s = strtok(s, delim))) {
    std::string str(s);
    // Remove whitespace from beginning
    while (isspace(str.front())) {
      str.erase(0, 1);
    }
    // Remove whitespace from end
    while (isspace(str.back())) {
      str.pop_back();
    }
    v.push_back(std::move(str));
    s = nullptr;
  }
  return v;
}

struct Record {
  std::string first_name;
  std::string last_name;
  unsigned int age;
  std::string date_of_birth;

  void swap(Record &that) {
    using std::swap;
    swap(first_name, that.first_name);
    swap(last_name, that.last_name);
    swap(age, that.age);
    swap(date_of_birth, that.date_of_birth);
  }
  void printRecordDescription() const {
    std::cout << "\nRecord {\n  FirstName: " << first_name
              << ",\n  LastName: " << last_name << ",\n  Age: " << age
              << ",\n  DOB: " << date_of_birth << ",\n}\n";
  }
  static bool verifyRecordFromLine(const std::vector<std::string> &record_v) {
    if (record_v.size() != 3) {
      return false;
    }
    auto &age = record_v[1];
    auto &dob = record_v[2];
    try {
      int a = std::stoi(age);
      if (a < 0) throw "";
    } catch (...) {
      std::cout << "Error: Age parameter is incorrect, please enter a positive "
                   "integer\n";
      return false;
    }
    const char *dob_err = "Error: Invalid Date-Of-Birth, format is MM-DD-YY\n";
    if (dob.size() != 8) {
      std::cout << dob_err;
      return false;
    }
    auto field = [](int i) {
      if (i < 0 || i > 9) {
        throw std::out_of_range("Index of DOB is out of range");
      }
      return i == 2 || i == 5;
    };
    for (int i = 0; i < 8; i++) {
      switch ((int)field(i)) {
        case 1:
          if (dob[i] != '-') {
            std::cout << dob_err;
            return false;
          }
          break;
        case 0:
          if (dob[i] < '0' || dob[i] > '9') {
            std::cout << dob_err;
            return false;
          }
          break;
        default:
          throw "Unreachable";
      }
    }
    return true;
  }

  static bool LessThan(const Record &rA, const Record &rB) {
    if (rA.first_name.size() < rB.first_name.size()) {
      return true;
    } else if (rA.first_name.size() == rB.first_name.size()) {
      if (rA.last_name.size() < rB.last_name.size()) {
        return true;
      } else if (rA.last_name.size() == rB.last_name.size()) {
        if (rA.age < rB.age) {
          return true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  static bool Equal(const Record &rA, const Record &rB) {
    return rA.first_name == rB.first_name && rA.last_name == rB.last_name &&
           rA.age == rB.age && rA.date_of_birth == rB.date_of_birth;
  }
  static bool GreaterThan(const Record &rA, const Record &rB) {
    return !Equal(rA, rB) && !LessThan(rA, rB);
  }
};

template <>
struct std::less<Record> {
  bool operator()(const Record &A, const Record &B) const noexcept {
    if (Record::LessThan(A, B)) return true;
    return false;
  }
};

template <>
struct std::greater<Record> {
  bool operator()(const Record &A, const Record &B) const noexcept {
    if (Record::GreaterThan(A, B)) return true;
    return false;
  }
};

template <>
struct std::equal_to<Record> {
  bool operator()(const Record &A, const Record &B) const noexcept {
    if (Record::Equal(A, B)) return true;
    return false;
  }
};

void pressAnyKey() {
  std::cout << "Press any key to continue...\n";
  //(void)getchar();
}
// Data Structures
DoublyLinkedList<Record> list;
AVLTree<Record, balancing_factor_t::caching> tree;
Stack<Record> stack;
DEQueue<Record> queue;

void getOneRecordFromInput(std::string &line) {
  auto v = stringPrepare(line, ",");
  if (!Record::verifyRecordFromLine(v)) {
    std::cout << "Incorrect record given as input, please retry.\n";
    return;
  }
  auto name_v = stringPrepare(v[0], " ");
  if (name_v.size() != 2) {
    std::cout << "Name specification incorrect in input, please retry.\n";
    return;
  }
  Record rec{name_v[0], name_v[1], static_cast<unsigned>(std::stoi(v[1])),
             v[2]};
  queue.pushBack(rec);
}

int main() {
  for (;;) {
    std::cout << "\nEnter description in form of: FirstName LastName, Age, "
                 "MM-DD-YY\n";
    std::string line;
    std::getline(std::cin, line);
    if (line == "finish") break;
    getOneRecordFromInput(line);
  }
  std::cout << "Finished STEP 1: Store all records in a queue.\n";
  decltype(queue) new_queue;
  while (!queue.isEmpty()) {
    auto rec = queue.getFront();
    queue.popFront();
    rec.printRecordDescription();
    new_queue.pushBack(rec);
  }
  std::cout << "Finished STEP 2: Dequeue, Print, Requeue\n";
  pressAnyKey();

  while (!new_queue.isEmpty()) {
    stack.pushStack(new_queue.getFront());
    new_queue.popFront();
  }
  while (!stack.isEmpty()) {
    auto rec = stack.getTopOfStack();
    queue.pushBack(rec);
    stack.popStack();
    rec.printRecordDescription();
  }
  std::cout << "Finished STEP 3: Dequeue, Add to Stack, Pop from Stack, Insert "
               "to Queue, Print\n";
  pressAnyKey();

  while (!queue.isEmpty()) {
    tree.insert(queue.getFront());
    queue.popFront();
  }
  std::cout << "Finished STEP 4: Dequeue, Add to Binary Tree\n";
  tree.traversePreOrder(&Record::printRecordDescription);
  std::cout << "Finished STEP 5(a): PreOrder Traversal\n";
  pressAnyKey();
  tree.traversePostOrder(&Record::printRecordDescription);
  std::cout << "Finished STEP 5(b): PostOrder Traversal\n";
  pressAnyKey();

  tree.traverseInOrder([](const Record &r) {
    list.pushBack(r);
    r.printRecordDescription();
  });
  std::cout << "Finished STEP 6: InOrder Traversal, Move from Binary Tree to "
               "List ADT\n";
  pressAnyKey();

  quickSort(list.begin(), list.end());
  std::cout << "Printing sorted list\n";
  for (auto i : list) {
    i.printRecordDescription();
  }
  std::cout << "Finished STEP 7: QuickSort Linked List\n";
  pressAnyKey();

  std::cout << "Enter final record:\n";
  while (queue.isEmpty()) {
    std::string line;
    std::getline(std::cin, line);
    getOneRecordFromInput(line);
  }

  insertSorted(list.begin(), list.end(), queue.getBack());
  std::cout << "Printing sorted list\n";
  for (auto i : list) {
    i.printRecordDescription();
  }

  std::cout << "Finished STEP 8: Insert Record in sorted manner\n";
  std::cout << "Finished all steps Successfully!\n";
  return 0;
}
