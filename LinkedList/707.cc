struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
};

class MyLinkedList {
public:
  MyLinkedList() {
    head_ = new ListNode();
    tail_ = head_;
    size_ = 0;
  }

  int get(int index) {
    if (index >= size_) {
      return -1;
    }
    auto pt = head_;
    while (index >= 0) {
      pt = pt->next;
      --index;
    }
    return pt->val;
  }

  void addAtHead(int val) {
    auto pt = new ListNode();
    if (size_ == 0) {
      head_->next = pt;
      tail_ = pt;
    } else {
      auto cur_first = head_->next;
      pt->next = cur_first;
      head_->next = pt;
    }
    pt->val = val;
    ++size_;
  }

  void addAtTail(int val) {
    auto pt = new ListNode();
    pt->val = val;
    tail_->next = pt;
    tail_ = pt;
    ++size_;
  }

  void addAtIndex(int index, int val) {
    if (index > size_) {
      return;
    }
    auto nn = new ListNode();
    nn->val = val;
    if (index == size_) {
      tail_->next = nn;
      tail_ = nn;
      size_++;
      return;
    }
    auto pt = head_;
    while (index > 0) {
      pt = pt->next;
      index--;
    }
    auto pt_next = pt->next;
    nn->next = pt_next;
    pt->next = nn;
    size_++;
    return;
  }

  void deleteAtIndex(int index) {
    if (index >= size_) {
      return;
    }
    auto pt = head_;
    while (index > 0) {
      pt = pt->next;
      index--;
    }
    auto to_be_delete = pt->next;
    if (to_be_delete == tail_) {
      tail_ = pt;
    } else {
      pt->next = to_be_delete->next;
    }
    size_--;
    delete to_be_delete;
  }
  ListNode *head_;
  ListNode *tail_;
  int size_;
};
int main(){};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
