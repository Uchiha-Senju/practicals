#if !defined(VARAD_GRAPH_H_INCLUDED)
  #define VARAD_GRAPH_H_INCLUDED
  
  #include "list.h"
  
  namespace graph_h {
    template <class T>
    class Functor {
      virtual bool function(T& a, T& b) = 0;
      inline bool operator(T& a, T& b) {
        return function(a, b);
      }
    }
  }
  
  template <class T>
  class Graph {
    class Vertex {
      
      T data;
      
      list<Vertex*> edges;
      
      Vertex() : data(), edges() {}
      Vertex(Vertex* edge_list, unsigned int edge_count) : edges(edge_list, edge_count) {}
      Vertex(Vertex& old_vertex) : data(old_vertex.data), edges(old_vertex.edges) {}
      ~Vertex() {
        data.~T();
        edge_list.~list();
      }
      
      bool isConnected() {
        return edges.len() != 0;
      }
      bool isConnectedWithVertex(Vertex* other_vertex) {
        return edges.includes(other_vertex) != -1;
      }
      bool isConnectedWithVertex(Vertex& other_vertex) {
        return isConnectedWithVertex(&other_vertex);
      }
      void connectTo(Vertex* other_vertex) {
        edges.append(other_vertex);
      }
      void disconnectFrom(Vertex* other_vertex) {
        int i = edges.includes(other_vertex);
        if (i != -1)
          edges.remove(i);
      }
      void connectTo(Vertex& other_vertex) {
        connectTo(&other_vertex);
      }
      void disconnectFrom(Vertex& other_vertex) {
        disconnectFrom(&other_vertex);
      }
    };
    
    public :
      list<Vertex> vertex_list;
      
      Graph() : vertex_list() {}
      Graph(Graph& old_graph) : vertex_list(old_graph.vertex_list) {}
      
      void makeConnections(graph_h::Functor& func) {
        for (list<Vertex>::Iterator i(vertex_list); not i.hasEnded(); i++) 
          for (list<Vertex>::Iterator j = i + 1; not j.hasEnded(); j++) 
            if (func(i().data, j.data())) {
              i().connectTo(j());
              j().connectTo(i());
            }
      }
      
      list<list<Vertex*>> colorVertices() {
        list<list<Vertex*>> color_list;
        
        for (list<Vertex>::Iterator i(vertex_list); not i.hasEnded(); i++) {
          list<list<Vertex*>>::Iterator color(color_list);
          // Determine if vertex is connected to any other colored vertex
          bool is_connected;
          for (is_connected; not (color.hasEnded() or is_connected); color++)
            for (list<Vertex*>::Iterator j(color()), isConnected = false; not (j.hasEnded() or is_connected); ++j)
              is_connected |= i().isConnectedWithVertex(j());
          if (color.hasEnded() and is_connected)
            color.last();
          if (not color.hasEnded()) {
            color.append(i())
          } else {
            list<Vertex*> new_color;
            new_color.append(i());
            color_list.append(new_color);
          }
        }
        
        return color_list;
      }
  }
  
#endif