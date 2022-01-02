#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> pii_v;
typedef vector<pii_v> matrix_graph;
typedef vector<int> iv;

struct minWeight {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

pii pr(int value, int weight) {
    pii pair(value, weight);
    return pair;
}

class DijkstrasAlgo {
    matrix_graph graph;
    int vertices;

public:
    DijkstrasAlgo(matrix_graph graph) {
        this->graph = graph;
        this->vertices = graph.size();
    }

    void find_shortest_paths(int src) {
        // declare and initialize distances, with max int type values
        iv dist;
        for (int i = 0; i < this->vertices; i++) {
            dist.push_back(INT_MAX);
        }

        // intializing the source distance as 0.
        dist[src] = 0;

        // declare a priority queue, which prioritises, smaller weighted values
        priority_queue<pii, vector<pii>, minWeight> pq;
        // as min-weight to go from src to src is 0.
        pq.push(pr(src, 0));

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();

            int current_weight = top.second;

            // traverse the adjacency list corresponding to value of current element
            // in the priority queue.
            for (int i = 0; i < graph[top.first].size(); i++) {
                pii current_pr = graph[top.first][i];

                // check if we find a better distance
                if (current_weight + current_pr.second < dist[current_pr.first]) {
                    dist[current_pr.first] = current_weight + current_pr.second;
                    pq.push(current_pr);
                }
            }
        }

        // print the distances
        for (int i = 0; i < dist.size(); i++) {
            cout << i << " -> " << dist[i] << endl;
        }
    }
};

void print_graph(matrix_graph graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++) {
            pii pair = graph[i][j];
            cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    matrix_graph graph;

    pii_v zero = {
        pr(1, 1),
        pr(2, 3),
        pr(3, 2),
        pr(4, 1)};

    pii_v one = {
        pr(0, 1),
        pr(3, 3),
        pr(4, 4)};

    pii_v two = {
        pr(0, 3),
        pr(3, 1),
        pr(4, 1)};

    pii_v three = {
        pr(1, 3),
        pr(2, 1),
        pr(0, 2)};

    pii_v four = {
        pr(0, 5),
        pr(2, 1),
        pr(1, 4)};

    graph.push_back(zero);
    graph.push_back(one);
    graph.push_back(two);
    graph.push_back(three);
    graph.push_back(four);

    print_graph(graph);

    cout << "\nFinding shortest paths from 0" << endl;

    DijkstrasAlgo *d = new DijkstrasAlgo(graph);

    d->find_shortest_paths(0);

    return 0;
}
