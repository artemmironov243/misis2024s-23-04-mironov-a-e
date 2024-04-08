#pragma once
#ifndef QueueLstPr_HPP
#define QueueLstPr_HPP

#include <cstddef>

class QueueLstPr {
public:
    QueueLstPr() = default;
    QueueLstPr(const QueueLstPr&);
    QueueLstPr(QueueLstPr&&) noexcept;
    QueueLstPr& operator=(const QueueLstPr&);
    QueueLstPr& operator=(QueueLstPr&&) noexcept;
    ~QueueLstPr();

    bool IsEmpty() const noexcept;
    void Pop() noexcept;
    void Push(const float& val);
    float& Top();
    const float& Top() const;
    void Clear() noexcept;

private:
    struct Node {
        float val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

#endif