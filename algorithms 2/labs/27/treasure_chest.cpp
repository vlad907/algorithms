#include "treasure_chest.h"

/*
   * Add an item to the end of the chest.
   * @param Item& item_to_add - The item to be added to the end of the chest
   */
  void TreasureChest::AddItem(const Item& item_to_add) {

  }

  /*
   * Insert an item at the specified zero-indexed position in the chest. If
   * position is not valid for the chest, add the item to the end of the chest.
   * Note this function inserts, not replaces.
   * @param Item& item_to_add - The item to be inserted into the chest
   * @param u-int position    - The zero-indexed position where the insertion is
   *                            to take place.
   */
  void TreasureChest::InsertItem(const Item& item_to_add, unsigned int position) {

  }

  /*
   * Get a pointer to an item at a specified zero-indexed position in the chest.
   * @param u-int position - The zero-indexed position of the item
   * @return const Item* - A pointer to the item if position is valid, else NULL
   */
  const Item* TreasureChest::GetItem(unsigned int position) {

  }

  /*
   * Remove an item from the chest at a specified zero-indexed position.
   * @param u-int position - The zero-indexed position of the item
   * @return Item          - A copy of the Item removed from the chest
   * @throw string("ERROR: Remove at invalid position") if position is not valid
   */
  Item TreasureChest::RemoveItem(unsigned int position) {

  }

  /*
   * Clear the chest of all items.
   */
  void TreasureChest::Clear() {

  }

  /*
   * Check to see if the chest is empty.
   * @return bool - True if the chest is empty, else false
   */
  bool TreasureChest::Empty() const {

  }

  /*
   * Get the size/number of items currently in the chest.
   * @return u-int - The current size of the chest
   */
unsigned int TreasureChest::GetSize() const {

}

  /*
   * Sort the items in the chest by name, using the sort function
   * from the C++ standard algorithm library.
   */
  void TreasureChest::SortByName() {

  }

  /*
   * Sort the items in the chest by value, using the sort function
   * from the C++ standard algorithm library.
   */
  void TreasureChest::SortByValue() {

  }

  /*
   * Sort the items in the chest by quantity, using the sort function
   * from the C++ standard algorithm library.
   */
  void TreasureChest::SortByQuantity() {

  }

  /*
   * Place the names of the items in the chest on the specified stream,
   * formatted as ITEM_NAME, ITEM_NAME, ..., ITEM_NAME
   * Places "Chest Empty!" on the stream if the chest is empty
   */
  friend ostream& operator<<(ostream& outs, const TreasureChest& src) {
    
  }

  /*
   * Returns a string representation of what the overloaded << operator would
   * output. Remember: 'this' is a keyword that points to the current object
   * @uses Overloaded << Operator
   * @return string - A string in the format ITEM_NAME, ... or "Chest Empty!"
   */
  string TreasureChest::ToString() {

  }