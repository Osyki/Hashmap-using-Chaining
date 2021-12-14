//
// Created by Ekyso on 12/14/2021.
//

class iterator {
public:


    /** De-reference an iterator */
    Entry_Type &operator*() const {
        if (*this == the_parent->end()) {
            throw std::invalid_argument("Attemt to de-reference end()");
        }
        return *the_pos;
    }

    /** De-reference an iterator */
    Entry_Type *operator->() const {
        if (*this == the_parent->end()) {
            throw std::invalid_argument("Attempt to de-reference end()");
        }
        return &(*the_pos);
    }

    /** Prefix increment operator */
    iterator &operator++() {
        ++the_pos;
        advance();
        return *this;
    }

    /** Postfix increment operator */
    iterator operator++(int) {
        const_iterator temp(*this);
        ++(*this);
        return temp;
    }

    /** Equality operator */
    bool operator==(const iterator &other) const {
        return the_index == other.the_index
               && the_pos == other.the_pos;
    }

    /** Inequality operator */
    bool operator!=(const iterator &other) const {
        return !operator==(other);
    }

private:

    // Allow the map to access the private constructor and data fields
    friend class hash_map<Key_Type, Value_Type>;

    // Allow const_iterators to access private data fields
    friend class const_iterator;

    /** Advance the iterator to the next position */
    void advance() {
        if (the_pos != the_parent->the_buckets[the_index].end()) {
            return;
        } else {
            while (the_index < (the_parent->the_buckets.size() - 1)) {
                the_index++;
                the_pos = the_parent->the_buckets[the_index].begin();
                if (the_pos != the_parent->the_buckets[the_index].end())
                    return;
            }
            the_pos = the_parent->the_buckets[the_index].end();
            return;
        }
    }

    /** Constructor */
    iterator(hash_map<Key_Type, Value_Type> *parent,
             size_t index,
             typename std::list<Entry_Type>::iterator pos) :
            the_parent(parent),
            the_index(index),
            the_pos(pos) {};

    /** The map containing this iterator */
    hash_map<Key_Type, Value_Type> *the_parent;

    /** The index of the bucket */
    size_t the_index;

    /** The iterator within the bucket */
    typename std::list<Entry_Type>::iterator the_pos;
};
