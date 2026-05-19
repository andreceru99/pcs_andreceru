#ifndef GRAPHVIZ_HPP
#define GRAPHVIZ_HPP

#include <fstream>
#include <string>

#include "unidirected_graph.hpp"

void export_to_dot(
    const unidirected_graph& G,
    const std::string& filename
)
{
    std::ofstream ofs(filename);

    ofs << "graph G {\n";

    for (const auto& edge : G.all_edges())
    {
        ofs << "    "
            << edge.from()
            << " -- "
            << edge.to()
            << ";\n";
    }

    ofs << "}\n";
}

#endif