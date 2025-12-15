#include "forward_list_impl.h"

    ForwardList::ForwardList(): head_(nullptr) {}

    // copy constructor
    ForwardList::ForwardList(const ForwardList& rhs)
    {
        if(rhs.head_ == nullptr)
        {
            return;
        }

        Node* current_element = rhs.head_;
        Node* previous_element = nullptr;

        while (current_element != nullptr)
        {
            Node* copied_element = new Node(current_element -> value_);
            if(previous_element == nullptr)
            {
                head_ = copied_element;
            }
            else
            {
                previous_element -> next_ = copied_element;
            }

            previous_element = copied_element;
            current_element = current_element -> next_;
        }
    }

    // Constructs a ForwardList with `count` copies of elements with value `value`.
    ForwardList::ForwardList(size_t count, int32_t value): head_(nullptr)
    {
        for(size_t i = 0; i < count; ++i)
        {
            PushFront(value);
        }
    }

    // Constructs a ForwardList with std::initializer_list<int32_t>
    ForwardList::ForwardList(std::initializer_list<int32_t> init): head_(nullptr)
    {
        for(auto iterator = std::rbegin(init); iterator != std::rend(init); ++iterator)
        {
            PushFront(*iterator);
        }
    }

    // operator= overloading
    ForwardList& ForwardList::operator=(const ForwardList& rhs)
    {
        if(this == &rhs)
        {
            return *this;
        }

        Clear();
        
        if(rhs.head_ == nullptr)
        {
            return *this; // rhs is empty
        }

        Node* current_element = rhs.head_;
        Node* previous_element = nullptr;

        while(current_element != nullptr)
        {
            Node* new_element = new Node(current_element -> value_);
            if(previous_element == nullptr)
            {
                head_ = new_element;
            }
            else
            {
                previous_element -> next_ = new_element;
            }
            previous_element = new_element;
            current_element = current_element -> next_;
        }

        return *this;
    }

    // destructor
    ForwardList::~ForwardList()
    {
        Clear();
    }

    // insert new element on the top of the list
    void ForwardList::PushFront(int32_t value)
    {
        Node* new_element = new Node(value);
        new_element -> next_ = head_;
        head_ = new_element;
    }

    // delete first element of the list
    void ForwardList::PopFront()
    {
        if(head_ == nullptr)
        {
            return;
        }
        Node* deleting_element = head_;
        head_ = head_ -> next_;
        delete deleting_element;
    }

    // remove every occurence of an element in the list
    // whose value equals to param `value`,
    // the remaining elements must remain in the same order
    void ForwardList::Remove(int32_t value)
    {
        Node* current_element = head_;
        Node* previous_element = nullptr;

        while(current_element != nullptr)
        {
            if(current_element -> value_ == value)
            {
                Node* deleting_element = current_element;
                if(previous_element == nullptr)
                {
                    head_ = current_element -> next_;
                    current_element = head_;
                }
                else
                {
                    previous_element -> next_ = current_element -> next_;
                    current_element = current_element -> next_;
                }

                delete deleting_element;
            }
            else
            {
                previous_element = current_element;
                current_element = current_element -> next_;
            }
        }
    }

    // erases all the elements
    void ForwardList::Clear()
    {
        Node* current_element = head_;
        while(current_element != nullptr)
        {
            Node* next_element = current_element -> next_;
            delete current_element;
            current_element = next_element;
        }
        head_ = nullptr;
    }

    // find list's element by the `value`
    // returns true, if element exists
    // otherwise, returns false
    bool ForwardList::FindByValue(int32_t value)
    {
        Node* current_element = head_;
        while(current_element != nullptr)
        {
            if(current_element -> value_ == value)
            {
                return true;
            }
            current_element = current_element -> next_;
        }
        return false;
    }

    // print list's elements to stream separated by space
    void ForwardList::Print(std::ostream& out)
    {
        Node* current_element = head_;
        while(current_element != nullptr)
        {
            out << current_element -> value_;
            if(current_element -> next_ != nullptr)
            {
                out << " ";  // divider string
            }
            current_element = current_element -> next_;
        }
    }

    // get first element of the list
    int32_t ForwardList::Front() const
    {
        if(head_ == nullptr)
        {
            throw "Error: No first element!";
            return 0;
        }
        return head_ -> value_;
    }

    // get size of the list
    size_t ForwardList::Size() const
    {
        Node* current_element = head_;
        size_t size = 0;
        while(current_element != nullptr)
        {
            size++;
            current_element = current_element -> next_;
        }
        return size;
    }



    
    // iterators
    ForwardList::ForwardListIterator ForwardList::begin()
    {
        return ForwardListIterator(head_);
    }

    ForwardList::ForwardListIterator ForwardList::end()
    {
        return ForwardListIterator(nullptr);
    }

    ForwardList::ForwardListIterator ForwardList::begin() const
    {
        return ForwardListIterator(head_);
    }

    ForwardList::ForwardListIterator ForwardList::end() const
    {
        return ForwardListIterator(nullptr);
    }