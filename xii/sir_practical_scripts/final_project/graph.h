#if !defined(VARAD_GRAPH_H_INCLUDED)
  #define VARAD_GRAPH_H_INCLUDED
  
  #include "list.h"
  #include <iostream>
  #include <iomanip>
  
  namespace graph_h {
    // Add const to type if it is a pointer
    template <class T>
    struct AddConstToType {
      typedef T type;
    };
    template <class T>
    struct AddConstToType<T*> {
      typedef const T* type;
    };
    
    template <class T>
    class BinaryFunctor {
      public :
        virtual bool function(const typename AddConstToType<T>::type& a, const typename AddConstToType<T>::type& b) const = 0;
        inline bool operator()(const typename AddConstToType<T>::type& a, const typename AddConstToType<T>::type& b) const {
          return function(a, b);
        }
    };
  }
  
  template <class T>
  class Graph {
    public :
      class Vertex {
        public : 
          T data;
          List<Vertex*> edges;
          // Vertex Constructors
          Vertex() : data(), edges() {}
          // Weird cast of const T new_data to T so that it can be copied to data
          Vertex(const typename graph_h::AddConstToType<T>::type& new_data) : data((T)new_data), edges() {}
          Vertex(const typename graph_h::AddConstToType<T>::type& new_data, Vertex** edge_list, unsigned int edge_count) 
            : data((T)new_data), edges(edge_list, edge_count) {}
          Vertex(const Vertex& old_vertex) : data(old_vertex.data), edges(old_vertex.edges) {}
          // Equivalence checks are dependent on the Vertex data, not the edges
          inline bool operator==(const Vertex& other_vertex) const {
            return data == other_vertex.data;
          }
          inline bool operator!=(const Vertex& other_vertex) const {
            return not (*this == other_vertex.data) ;
          }
          // Functions for edge management
          bool isConnected() const {
            return edges.len() != 0;
          }
          bool isConnectedWithVertex(const Vertex* const other_vertex) const {
            if (other_vertex != nullptr and other_vertex != this)
              return edges.includes(other_vertex) != -1;
            return false;
          }
          bool isConnectedWithVertex(const Vertex& other_vertex) const {
            return isConnectedWithVertex(&other_vertex);
          }
          void connectTo(const Vertex* const other_vertex) {
            if (other_vertex != nullptr and other_vertex != this) {
              if (edges.includes(other_vertex) == -1)
                edges.append(other_vertex);
            }
          }
          void disconnectFrom(const Vertex* const other_vertex) {
            if (other_vertex != nullptr and other_vertex != this) {
              int i = edges.includes(other_vertex);
              if (i != -1)
                edges.remove(i);
            }
          }
          void connectTo(const Vertex& other_vertex) {
            connectTo(&other_vertex);
          }
          void disconnectFrom(const Vertex& other_vertex) {
            disconnectFrom(&other_vertex);
          }
          // Vertex Destructor
          ~Vertex() {
            data.~T();
            for (typename List<Vertex*>::Iterator connected_vertex(edges); not connected_vertex.hasEnded(); connected_vertex++)
              connected_vertex()->disconnectFrom(this);
            edges.~List();
          }
      };
    
      List<Vertex> vertices;
      
      Graph() : vertices() {}
      Graph(Graph& old_graph) : vertices(old_graph.vertices) {}
      
      void makeVertex(const typename graph_h::AddConstToType<T>::type& data) {
        vertices.append(Vertex(data));
      }
      void removeVertex(unsigned int index) {
        vertices.remove(index);
      }
      
      void connectVertices(unsigned int i_1, unsigned int i_2) {
        Vertex* v_1 = &(vertices[i_1]);
        Vertex* v_2 = &(vertices[i_2]);
        
        if (v_1 == v_2 or v_1 == nullptr or v_2 == nullptr)
          return;
        
        v_1->connectTo(v_2);
        v_2->connectTo(v_1);
      }
      void disconnectVertices(unsigned int i_1, unsigned int i_2) {
        Vertex* v_1 = &(vertices[i_1]);
        Vertex* v_2 = &(vertices[i_2]);
        
        if (v_1 == v_2 or v_1 == nullptr or v_2 == nullptr)
          return;
        
        v_1->disconnectFrom(v_2);
        v_2->disconnectFrom(v_1);
      }
      
      void makeConnections(const graph_h::BinaryFunctor<T>& func) {
        // Cycle through each possible vertex pair and connect them
        // if the given function returns true
        for (typename List<Vertex>::Iterator i(vertices); not i.hasEnded(); i++) 
          for (typename List<Vertex>::Iterator j = i + 1; not j.hasEnded(); j++) 
            if (func(i().data, j().data)) {
              i().connectTo(j());
              j().connectTo(i());
            }
      }
      
      List<List<Vertex*>> colorVertices() {
        List<List<Vertex*>> color_list;
        
        for (typename List<Vertex>::Iterator i(vertices); not i.hasEnded(); i++) {
          typename List<List<Vertex*>>::Iterator color(color_list);
          // Determine if vertex is connected to any other colored vertex
          bool is_connected = true;
          // Come out color-checking loop if colors have run out or 
          // the current vertex is not connected to any vertex of the given color
		  // 
		  // Don't increment color if none are connected
          for (; not (color.hasEnded() or not is_connected); is_connected ? color++ : color)
            // Come out of vertex-connection-checking loop
            // if there are no more vertices to check or
            // the current vertex is connected to any vertex of the given color
            for (typename List<Vertex*>::Iterator j( (is_connected = false, color()) ); not (j.hasEnded() or is_connected); ++j)
              is_connected |= i().isConnectedWithVertex(j());
          // If current vertex was not connected to any in the last color,
          // switch back to it
          if (color.hasEnded() and not is_connected)
            color.last();
          if (not color.hasEnded()) {
            // Color the vertex if an unconnected color was found
            color().append(&i());
          } else {
            // Make a new color if the vertex is connected to all the current colors
            List<Vertex*> new_color;
            new_color.append(&i());
            color_list.append(new_color);
          }
        }
        
        return color_list;
      }
  };
  
#endif