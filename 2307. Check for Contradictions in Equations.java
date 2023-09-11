class Solution {
    public class Edge{
        String nextVertex;
        Double weight;
        Edge(String nextVertex, Double weight){
            this.nextVertex = nextVertex;
            this.weight = weight;
        }
        @Override
        public int hashCode() {
            int result = nextVertex != null ? nextVertex.hashCode() : 0;
            long temp = Double.doubleToLongBits(weight);
            result = 31 * result + (int) (temp ^ (temp >>> 32));
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;

            Edge otherEdge = (Edge) obj;
            if (nextVertex != null ? !nextVertex.equals(otherEdge.nextVertex) : otherEdge.nextVertex != null) return false;
            if (Double.compare(otherEdge.weight, weight) != 0) return false;
            return true;
        }
    }
    public void dfs(String node, String target, HashMap<String, ArrayList<Edge>> adj, Double currentDist, Double given, int[] flag, HashSet<String> vis){
        if(vis.contains(node)) return;
        vis.add(node);
        if(node.equals(target)){
            Double diff = currentDist - given;
            if(diff < 0){
                diff *= -1;
            }
            if(diff > 0.00001){
                flag[0] = 1;
            }
            return;
        }
        for(Edge edge: adj.get(node)){
            if(!vis.contains(edge.nextVertex)){
                dfs(edge.nextVertex, target, adj, currentDist*edge.weight, given, flag, vis);
            }
        }
    }
    public String getParent(String node, HashMap<String, String> parent){
        if(parent.containsKey(node)){
            String currpar = parent.get(node);
            if(currpar.equals(node)) return node;
            else return getParent(currpar, parent);
        }
        return null;
    }
    public void merge(String p1, String p2, HashMap<String, String> parent){
        // lazy as duck
        parent.put(p2, p1);
    }
    public boolean checkContradictions(List<List<String>> equations, double[] values) {
        int neq = equations.size();
        HashMap<String, String> parent = new HashMap<>();
        HashMap<String, ArrayList<Edge>> adj = new HashMap<>();
        for(int i=0; i<neq; i++){
            String node1 = equations.get(i).get(0);
            String node2 = equations.get(i).get(1);
            if(node1.equals(node2) && values[i]!=1) return true;
            if(node2.equals(node1)){
                if(!parent.containsKey(node1)){
                    parent.put(node1, node1);
                    ArrayList<Edge> emptyList = new ArrayList<>();
                    adj.put(node1, emptyList);
                }
            }
            Double edgeLen = values[i];
            boolean isNode1Present = parent.containsKey(node1);
            boolean isNode2Present = parent.containsKey(node2);
            if(!isNode1Present && isNode2Present){
                parent.put(node1, parent.get(node2));
                ArrayList<Edge> emptyList = new ArrayList<>();
                adj.put(node1, emptyList);
                adj.get(node1).add(new Edge(node2, edgeLen));
                adj.get(node2).add(new Edge(node1, (1/edgeLen)));
            }
            else if(isNode1Present && !isNode2Present){
                parent.put(node2, parent.get(node1));
                ArrayList<Edge> emptyList = new ArrayList<>();
                adj.put(node2, emptyList);
                adj.get(node2).add(new Edge(node1, (1/edgeLen)));
                adj.get(node1).add(new Edge(node2, edgeLen));
            }
            else if(!isNode1Present && !isNode2Present){
                parent.put(node1, node1);
                parent.put(node2, node1);
                adj.put(node1, new ArrayList<Edge>());
                adj.put(node2, new ArrayList<Edge>());
                adj.get(node1).add(new Edge(node2, edgeLen));
                adj.get(node2).add(new Edge(node1, (1/edgeLen)));
            }
            else{
                String parent1 = getParent(node1, parent);
                String parent2 = getParent(node2, parent);
                System.out.println(parent1);
                System.out.println(parent2);
                if(parent1.equals(parent2)){
                    // System.out.println("DFS will be done. God won\'t stop me");
                    int[] flag = new int[1];
                    flag[0] = 0;
                    HashSet<String> vis = new HashSet<>();
                    dfs(node1, node2, adj, 1.0, values[i], flag, vis);
                    if(flag[0]==1) return true;
                }
                else{ 
                    adj.get(node1).add(new Edge(node2, edgeLen));
                    adj.get(node2).add(new Edge(node1, (1/edgeLen)));
                    merge(parent1, parent2, parent);
                }
            }
        }
        return false;
    }
}
