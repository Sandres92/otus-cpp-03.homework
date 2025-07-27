#pragma once
#include <iostream>

namespace otus
{
    template <typename T, typename Allocator = std::allocator<T>>
    class CustomForwardList
    {
    private:
        struct Node
        {
            T data;
            Node *next;

            Node(T data, Node *next) : data(data), next(next)
            {
            }
        };

        Node *head = nullptr;

        using NodeAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
        NodeAllocator alloc;

    public:
        CustomForwardList() : head(nullptr)
        {
        }

        CustomForwardList(const CustomForwardList &other)
        {
        }

        ~CustomForwardList()
        {
        }

        void push_front(const T &newT)
        {
            Node *newNode = alloc.allocate(1);
            alloc.construct(newNode, newT, head);
            head = newNode;
        }

        // void clear()
        //{
        //     Node *node = head;
        //     while (node != nullptr)
        //     {
        //         Node *nodeNext = head->next;
        //         alloc.destroy(node);
        //         node = nodeNext;
        //     }
        //
        //    head = nullptr;
        //}

        bool empty() const noexcept
        {
            return head == nullptr;
        }

        size_t size() const noexcept
        {
            size_t size = 0;
            Node *node = head;
            while (node != nullptr)
            {
                ++size;
                node = node->next;
            }
            return size;
        }

        class Iter
        {
        private:
            Node *node;

        public:
            explicit Iter(CustomForwardList::Node *node = nullptr) : node(node) {}
            ~Iter() {}

            Iter &operator++()
            {
                if (node)
                {
                    node = node->next;
                }
                return *this;
            }

            bool operator==(const Iter &other) const
            {
                return node == other.node;
            }
            bool operator!=(const Iter &other) const
            {
                return !(*(this) == other);
            }

            const T &operator*() const
            {
                return node->data;
            }
            const T *operator->() const
            {
                return &(node->data);
            }
        };

        Iter begin() const
        {
            return Iter(head);
        }

        Iter end() const
        {
            return Iter(nullptr);
        }
    };

} // namespace otus
