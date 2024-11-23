#include "btNode.h"

// write definition for bst_insert here
void bst_insert(btNode*& root, int newInt)
{
   btNode* newNode = new btNode;
   newNode->data = newInt;
   newNode->left = 0;
   newNode->right = 0;

   if(root == 0)
   {
      root = newNode;
      return;
   }

   btNode* runner = root;

   while(runner != 0)
   {
      if(newInt == runner->data)
      {
         delete newNode;
         return;
      } 

      else if(newInt < runner->data)
      {
         if(runner->left == 0)
         {
            runner->left = newNode;
            return;
         }
         runner = runner->left;
      }
      else
      {
         if(runner->right == 0)
         {
            runner->right = newNode;
            return;
         }
         runner = runner->right;
      }
   }
}


// write definition for bst_remove here
bool bst_remove(btNode*& root, int remInt)
{
   if(root == 0) return false;

   if(remInt < root->data)
      return bst_remove(root->left, remInt);

   else if(remInt > root->data)
      return bst_remove(root->right, remInt);
   
   else
   {
      // Case 1: is a leaf with no children
      if(root->left == 0 && root->right == 0)
      {
         delete root;
         root = 0;
         return true;
      }

      // Case 2: one child
      else if(root->left == 0)
      {
         btNode* temp = root;
         root = temp->right;
         delete temp;
         return true;
      }

      else if (root->right == 0)
      {
         btNode* temp = root;
         root = temp->left;
         delete temp;
         return true;
      }

      // Case 3: two children
      else
      {
         // Find the inorder successor (smallest value in right subtree)
         btNode* successor = root->right;
         while (successor->left) 
         {
            successor = successor->left;
         }
         
         root->data = successor->data;
         
         // Remove the successor (which will be Case 1 or Case 2)
         return bst_remove(root->right, successor->data);
      }
   }

}

// write definition for bst_remove_max here

void bst_remove_max(btNode*& root)
{
   if(root == 0) return;

   if(root->right == 0)
   {
      btNode* temp = root;
      root = root->left;
      delete temp;
      return;
   }

   bst_remove_max(root->right);

}

void portToArrayInOrder(btNode* bst_root, int* portArray)
{
   if (bst_root == 0) return;
   int portIndex = 0;
   portToArrayInOrderAux(bst_root, portArray, portIndex);
}

void portToArrayInOrderAux(btNode* bst_root, int* portArray, int& portIndex)
{
   if (bst_root == 0) return;
   portToArrayInOrderAux(bst_root->left, portArray, portIndex);
   portArray[portIndex++] = bst_root->data;
   portToArrayInOrderAux(bst_root->right, portArray, portIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}
