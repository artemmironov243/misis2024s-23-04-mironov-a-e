#include "queuelstpr/queuelstpr.hpp"

#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr& other) {
    Node* current = other.head_;
    while (current) {
        Push(current->val);
        current = current->next;
    }
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& other) {
    if (this != &other) {
        Clear();
        Node* current = other.head_;
        while (current) {
            Push(current->val);
            current = current->next;
        }
    }
    return *this;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& other) noexcept {
    if (this != &other) {
        Clear();
        head_ = other.head_;
        tail_ = other.tail_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
    }
    return *this;
}

QueueLstPr::QueueLstPr(QueueLstPr&& other) noexcept {
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
}

bool QueueLstPr::IsEmpty() const noexcept { return nullptr == head_; }

QueueLstPr::~QueueLstPr() { Clear(); }

void QueueLstPr::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
    }
    if (IsEmpty()) {
        tail_ = nullptr;
    }
}

void QueueLstPr::Push(const float& val) {
    if (IsEmpty()) {
        tail_ = new Node{ val };
        head_ = tail_;
    }
    else {
        if (val < head_->val) {
            Node* curr = new Node{ val };
            curr->next = head_;
            head_ = curr;
        }
        else if(val > tail_->val)  {
            Node* curr = new Node{ val };
            tail_->next = curr;
            tail_ = curr;
        }
        else {
            Node* curr = head_;
            Node* prev = nullptr;
            Node* new_node = new Node{ val };
            while (curr->val <= val) {
                prev = curr;
                curr = curr->next;
            }
            if (prev != nullptr) {
                prev->next = new_node;
            }
            new_node->next = curr;
        }
    }
    
}

float& QueueLstPr::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueLstPr - try get top form empty queue.");
    }
    return head_->val;
}

const float& QueueLstPr::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueLstPr - try get top form empty queue.");
    }
    return head_->val;
}

void QueueLstPr::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}