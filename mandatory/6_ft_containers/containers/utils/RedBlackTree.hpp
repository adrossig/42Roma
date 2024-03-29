#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>

#include "container_utils.hpp"
#include "map_iterator.hpp"
#include "rbt_reverse_iterator.hpp"

#define LEFT 0
#define RIGHT 1
#define left child[LEFT]
#define right child[RIGHT]

namespace ft
{
	template <class T, class Compare, class node_type>
	class RedBlackTree
	{
	public:
		typedef map_iterator<T, Compare, node_type> iterator;
		typedef map_iterator<const T, Compare, node_type> const_iterator;
		typedef node_type *node_pointer;
		typedef std::allocator<node_type> node_allocator;
		typedef typename std::allocator<T>::size_type size_type;

		RedBlackTree() : root(NULL), treeSize(0)
		{
			nodeAllocator = node_allocator();
			endNode = nodeAllocator.allocate(1);
			nodeAllocator.construct(endNode, node_type());
		}

		~RedBlackTree() { nodeAllocator.deallocate(endNode, 1); }

		void printTree() { printTree(root); }

		void printTree(node_pointer node)
		{
			if (node != NULL)
			{
				printTree(node->left);
				if (node->color == RED)
					std::cout << RED_COLOR << node->data << RESET << " | ";
				else
					std::cout << node->data << " | ";

				printTree(node->right);
			}
		}

		iterator begin()
		{
			if (treeSize == 0)
				return (end());
			node_pointer temp;
			temp = root;
			if (temp->child[0])
			{
				while (temp->child[0])
					temp = temp->child[0];
			}
			return (iterator(temp, endNode));
		}

		iterator end()
		{
			endNode->parent = root;
			return (iterator(endNode, endNode));
		}

		const_iterator begin() const
		{
			node_pointer temp;
			if (treeSize == 0)
				return (end());
			temp = root;
			if (temp->child[0])
			{
				while (temp->child[0])
					temp = temp->child[0];
			}
			return (const_iterator(temp, endNode));
		}

		const_iterator end() const
		{
			endNode->parent = root;
			return (const_iterator(endNode, endNode));
		}

		size_type size(void) const { return (treeSize); }

		size_type max_size(void) const { return (node_allocator().max_size()); }

		bool empty(void) const { return (treeSize == 0 ? true : false); }

		ft::pair<iterator, bool> insert(const T &value)
		{
			ft::pair<iterator, bool> result;
			node_pointer nodeRes;
			node_pointer newNode = nodeAllocator.allocate(1);

			nodeAllocator.construct(newNode, value);
			newNode->parent = NULL;
			newNode->child[0] = NULL;
			newNode->child[1] = NULL;
			result.second = true;
			if (treeSize == 0)
			{
				newNode->color = BLACK;
				root = newNode;
				result.first = iterator(newNode, this->endNode);
			}
			else
			{
				nodeRes = insertNode(root, newNode);
				if (nodeRes != newNode)
					result.second = false;
				result.first = iterator(nodeRes, this->endNode);
			}
			if (result.second)
				++treeSize;
			else
			{
				nodeAllocator.destroy(newNode);
				nodeAllocator.deallocate(newNode, 1);
			}

			return (result);
		}

		node_pointer insertNode(node_pointer &current, node_pointer &newNode)
		{
			node_pointer temp;
			if (c(current->data.first, newNode->data.first))
			{
				if (current->right == NULL)
				{
					insertBalanced(this, newNode, current, RIGHT);
					return newNode;
				}
				temp = current->right;
			}
			else if (c(newNode->data.first, current->data.first))
			{
				if (current->left == NULL)
				{
					insertBalanced(this, newNode, current, LEFT);
					return newNode;
				}
				temp = current->left;
			}
			else
				return current;

			while (temp)
			{
				if (c(temp->data.first, newNode->data.first))
				{
					if (temp->right == NULL)
					{
						insertBalanced(this, newNode, temp, RIGHT);
						return newNode;
					}
					temp = temp->right;
				}
				else if (c(newNode->data.first, temp->data.first))
				{
					if (temp->left == NULL)
					{
						insertBalanced(this, newNode, temp, LEFT);
						return newNode;
					}
					temp = temp->left;
				}
				else
					return temp;
			}
			return current;
		}

		node_pointer RotateDirRoot(RedBlackTree *Tree, node_pointer P, int dir)
		{
			node_pointer G = P->parent;
			node_pointer S = P->child[1 - dir];
			node_pointer C;
			if (S == NULL)
				return NULL;
			C = S->child[dir];
			P->child[1 - dir] = C;
			if (C != NULL)
				C->parent = P;
			S->child[dir] = P;
			P->parent = S;
			S->parent = G;
			if (G != NULL)
				G->child[P == G->right ? RIGHT : LEFT] = S;
			else
				Tree->root = S;
			return S;
		}

		void insertBalanced(RedBlackTree *Tree, node_pointer N, node_pointer P, int dir)
		{
			node_pointer G;
			node_pointer U;

			N->color = RED;
			N->left = NULL;
			N->right = NULL;
			N->parent = P;
			if (P == NULL)
				Tree->root = N;
			P->child[dir] = N;

			do
			{
				if (P->color == BLACK)
					return;

				if ((G = P->parent) == NULL)
				{
					P->color = BLACK;
					return;
				}

				dir = get_chid_dir(P);
				U = G->child[1 - dir];
				if (U == NULL || U->color == BLACK)
				{
					if (N == P->child[1 - dir])
					{
						RotateDirRoot(Tree, P, dir);
						N = P;
						P = G->child[dir];
					}
					RotateDirRoot(Tree, G, 1 - dir);
					P->color = BLACK;
					G->color = RED;
					return;
				}
				P->color = BLACK;
				U->color = BLACK;
				G->color = RED;
				if (G->parent == NULL)
					G->color = BLACK;
				N = G;
			} while ((P = N->parent) != NULL);

			return;
		}

		template <class U>
		size_type erase_key(U &k)
		{
			node_pointer result;
			result = find(root, k);
			if (result == NULL)
				return 0;
			erase(result);
			--treeSize;
			return 1;
		}

		void erase(node_pointer &node)
		{
			if (node->left == NULL && node->right == NULL)
			{
				if (node == root)
				{
					nodeAllocator.destroy(node);
					nodeAllocator.deallocate(node, 1);
					node = NULL;
					root = NULL;
					return;
				}
				if (node->color == RED)
				{
					node->parent->child[get_chid_dir(node)] = NULL;
					nodeAllocator.destroy(node);
					nodeAllocator.deallocate(node, 1);
					node = NULL;
				}
				else
					rbtRemove(this, node);
				return;
			}
			else if (node->right == NULL)
			{
				node_pointer temp = get_predecessor(node);
				replaceNode(node, temp);
				erase(temp);
			}
			else
			{
				node_pointer temp = get_successor(node);
				replaceNode(node, temp);
				erase(temp);
			}
			return;
		}

		void replaceNode(node_pointer &dest, node_pointer &source)
		{
			node_pointer newNode;
			newNode = nodeAllocator.allocate(1);
			nodeAllocator.construct(newNode, source->data);
			if (dest->parent)
			{
				int dir = get_chid_dir(dest);
				dest->parent->child[dir] = newNode;
			}
			else
			{
				root = newNode;
			}
			newNode->color = dest->color;
			newNode->right = dest->right;
			newNode->left = dest->left;
			if (dest->right)
				dest->right->parent = newNode;
			if (dest->left)
				dest->left->parent = newNode;
			newNode->parent = dest->parent;
			nodeAllocator.destroy(dest);
			nodeAllocator.deallocate(dest, 1);
		}
		node_pointer get_successor(node_pointer node)
		{
			node = node->right;
			while (node->left != NULL)
				node = node->left;
			return (node);
		}

		node_pointer get_predecessor(node_pointer node)
		{
			node = node->left;
			while (node->right != NULL)
				node = node->right;
			return (node);
		}

		void rbtRemove(RedBlackTree *tree, node_pointer N)
		{
			node_pointer P = N->parent;

			int dir;
			bool first_iteration = true;

			node_pointer S;
			node_pointer C;
			node_pointer D;

			dir = get_chid_dir(N);
			S = P->child[1 - dir];
			nodeAllocator.destroy(P->child[dir]);
			nodeAllocator.deallocate(P->child[dir], 1);
			P->child[dir] = NULL;

			do
			{
				if (!first_iteration)
				{
					dir = get_chid_dir(N);
					first_iteration = false;
				}
				S = P->child[1 - dir];
				if (S == NULL)
					return;
				D = S->child[1 - dir];
				C = S->child[dir];
				if (S->color == RED)
				{
					/// case 3
					if (C == NULL)
						return;
					P->color = RED;
					S->color = BLACK;
					RotateDirRoot(tree, P, dir);
					S = C;
					D = S->child[1 - dir];
				}
				if (D != NULL && D->color == RED)
				{
					// case 6
					RotateDirRoot(tree, P, dir);
					S->color = P->color;
					P->color = BLACK;
					D->color = BLACK;
					return;
				}
				if (C != NULL && C->color == RED)
				{
					// case 5
					RotateDirRoot(tree, S, 1 - dir);
					S->color = RED;
					C->color = BLACK;
					D = S;
					S = C;
					// case 6
					RotateDirRoot(tree, P, dir);
					S->color = P->color;
					P->color = BLACK;
					D->color = BLACK;
					return;
				}
				if (P->color == RED)
				{
					// case 4
					S->color = RED;
					P->color = BLACK;
					return;
				}
				// case 1
				S->color = RED;
				N = P;
			} while ((P = N->parent) != NULL);
			return;
		}

		template <class U>
		size_type count(U &toFind) const
		{
			if (find(root, toFind))
				return (1);
			return (0);
		}

		template <class U>
		iterator find(U &toFind)
		{
			node_pointer result;
			result = find(root, toFind);
			if (result == NULL)
				return (end());
			return (iterator(result, endNode));
		}

		template <class U>
		const_iterator find_const(U &toFind) const
		{
			node_pointer result;
			result = find(root, toFind);
			if (result == NULL)
				return (end());
			return (const_iterator(result, endNode));
		}

		template <class U>
		node_pointer find(node_pointer &curr, U &toFind)
		{
			if (curr == NULL)
				return (curr);
			if (c(curr->data.first, toFind))
				return (find(curr->child[1], toFind));
			if (c(toFind, curr->data.first))
				return (find(curr->child[0], toFind));

			return (curr);
		}

		template <class U>
		node_pointer find(node_pointer curr, U &toFind) const
		{
			if (curr == NULL)
				return (curr);
			if (c(curr->data.first, toFind))
				return (find(curr->child[1], toFind));
			if (c(toFind, curr->data.first))
				return (find(curr->child[0], toFind));

			return (curr);
		}

		void clear()
		{
			size_t s = size();
			for (size_t i = 0; i < s; ++i)
			{
				erase_key(begin()->first);
			}
		}

		void swap(RedBlackTree &other)
		{
			if (&other != this)
			{
				node_pointer root_tmp = root;
				node_pointer end_tmp = endNode;
				size_t size_temp = treeSize;
				endNode = other.endNode;
				root = other.root;
				treeSize = other.treeSize;
				other.root = root_tmp;
				other.endNode = end_tmp;
				other.treeSize = size_temp;
			}
			return;
		}

		template <class U>
		iterator lower_bound(const U &key)
		{
			iterator first = begin();
			iterator last = end();

			while (first != last)
			{
				if (!c(first->first, key))
					break;
				first++;
			}
			return first;
		}
		template <class U>
		const_iterator lower_bound_const(const U &key) const
		{
			const_iterator first = begin();
			const_iterator last = end();

			while (first != last)
			{
				if (!c(first->first, key))
					break;
				first++;
			}
			return first;
		}

		template <class U>
		iterator upper_bound(const U &key)
		{
			iterator first = begin();
			iterator last = end();

			while (first != last)
			{
				if (c(key, first->first))
					break;
				first++;
			}
			return first;
		}

		template <class U>
		const_iterator upper_bound_const(const U &key) const
		{
			const_iterator first = begin();
			const_iterator last = end();

			while (first != last)
			{
				if (c(key, first->first))
					break;
				first++;
			}
			return first;
		}

	private:
		node_allocator nodeAllocator;
		node_pointer root;
		node_pointer endNode;
		size_t treeSize;
		Compare c;

		bool get_chid_dir(node_pointer &node) { return (node == (node->parent)->right ? 1 : 0); }

	}; // end of class RedBlackTree

} // namespace ft
#endif
