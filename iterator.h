//
// Created by Ekyso on 12/14/2021.
//

#ifndef CH9_HASHMAP_CHAINING2_ITERATOR_H
#define CH9_HASHMAP_CHAINING2_ITERATOR_H


class iterator {
public:


    /** De-reference an iterator */
    Entry_Type &operator*() const {
        /*</exercise>*/
    }

    /** De-reference an iterator */
    Entry_Type *operator->() const {
        /*</exercise>*/
    }

    /** Prefix increment operator */
    iterator &operator++() {
        /*</exercise>*/
    }

    /** Postfix increment operator */
    iterator operator++(int) {
        /*</exercise>*/
    }

    /** Equality operator */
    bool operator==(const iterator &other) const {
        /*</exercise>*/
    }

    /** Inequality operator */
    bool operator!=(const iterator &other) const {
        /*</exercise>*/
    }

private:

    // Allow the map to access the private constructor and data fields
    friend class hash_map<Key_Type, Value_Type>;

    // Allow const_iterators to access private data fields
    friend class const_iterator;

    /** Advance the iterator to the next position */
    void advance() {
        /*</exercise>*/
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


#endif //CH9_HASHMAP_CHAINING2_ITERATOR_H
