#include "htree.hh"

HTree::HTree(int key,
             uint64_t value,
             tree_ptr_t left,   
             tree_ptr_t right)
{
    key_ = key;
    value_ = value;
    left_ = left;
    right_ = right;
}   

HTree::~HTree() //Simple destructor ensures we free up memory of values that our object held
{
    //delete &key_;
    //delete &value_;
    //delete &left_;
    //delete &right_;
}

int HTree::get_key() const
{
    return key_;
}

uint64_t HTree::get_value() const
{
    return value_;
}

HTree::tree_ptr_t HTree::get_child(Direction dir) const
{
    if (dir == Direction::LEFT)
    {
        return left_;
    }
    return right_;
}

HTree::path_t HTree::path_to(int key) const
{
    HTree::path_t path_taken;
    if(left_ && left_->contains_key(key)) //First confirm we have a left branch, then call the helper method on that branch
    {
        path_taken = left_->path_to(key);//Push_front seemed to be the easiest way to add our directio to our list,
        path_taken.push_front(Direction::LEFT);//So we first set our list equal to the output of our recursive step,
        return path_taken;//Then add the direction to the front of that list and return that.
    }
    else if (key_ == key)
    {
        return path_taken;//Our base case returns an empty list; again, this is checked after left since we are looking for the leftmost value
    }
    if(right_ && right_->contains_key(key))//Similar to as above
    {
        path_taken = right_->path_to(key);
        path_taken.push_front(Direction::RIGHT);
        return path_taken;
    }
    else
    {    
    assert(false);//Crash the program if something is invalid, as with HW5
    }
    return path_taken;//Return statement at end to make compiler happy
}       

bool HTree::contains_key(int key) const//Helper function that recursively checks if a tree contains a given key
{
    if (key_ == key) return true;
    if (left_ && left_->contains_key(key)) return true;//similar syntax to above to ensure we don't try to call a method on a non-object
    if (right_ && right_->contains_key(key)) return true;
    return false;
}








