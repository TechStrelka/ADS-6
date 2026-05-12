#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Item {
        T data;
        Item* next;
    };
    Item *head, *tail;
    Item* create(const T& data) {
        Item* item = new Item;
        item->data = data;
        item->next = nullptr;
      
        return item;
    }

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    ~TPQueue() {
        while (head) {
            pop();
        }
    }

    void push(const T& data) {
        Item* newItem = create(data);

        if (head == nullptr) {
            head = tail = newItem;
        }
        else if (data.prior > head->data.prior) {
            newItem->next = head;
            head = newItem;
        }
        else {
            Item* current = head;
            while (current->next != nullptr && current->next->data.prior >= data.prior) {
                current = current->next;
            }
            newItem->next = current->next;
            current->next = newItem;
            if (newItem->next == nullptr) {
                tail = newItem;
            }
        }
    }

    T pop() {
        if (head == nullptr) {
            return T(); 
        }

        Item* temp = head;
        T data = temp->data;

        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return data;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
