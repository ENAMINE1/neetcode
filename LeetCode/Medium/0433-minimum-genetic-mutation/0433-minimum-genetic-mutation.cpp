class Solution {
    bool inBank(string &mutation, vector<string> &bank)
    {
        for(int i = 0; i < bank.size(); i++)
        {
            if(bank[i] == mutation)
                return true;
        }
        return false;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // how to create the graph?
        // every gene takes to 3 more gene mutations with some of them being valid
        unordered_map<string,vector<string>> graph;
        queue<string> mutations;
        mutations.push(startGene);
        vector<char> geneCodes = {'A', 'T', 'G', 'C'};
        set<string> chosen;
        while(!mutations.empty())
        {
            string gene = mutations.front();
            chosen.insert(gene);
            mutations.pop();
            for(int idx = 0; idx < startGene.size(); idx++)
            {
                for(int i = 0; i < geneCodes.size(); i++)
                {
                    if(gene[idx] != geneCodes[i]){
                        string mutation = gene;
                        mutation[idx] = geneCodes[i];
                        if(inBank(mutation, bank))
                        {
                            graph[gene].push_back(mutation);
                            if(chosen.count(mutation) == 0)
                                mutations.push(mutation);
                        }
                    }
                }
            }
        }
        // for(auto &[s, v]: graph)
        // {
        //     cout<<s<<" - ";
        //     for(auto &el: v)
        //         cout<<el<<", ";
        //     cout<<endl;
        // }
        // return 0;
        
        // bfs
        queue<string> q;
        unordered_map<string, int> dist;
        q.push(startGene);
        dist[startGene] = 0;
        while(!q.empty())
        {
            string gene = q.front();
            q.pop();
            for(string &nn : graph[gene])
            {
                if(dist.find(nn) == dist.end())
                {
                    // the neighbour is not visited yet
                    dist[nn] = dist[gene] + 1;
                    q.push(nn);
                }
            }
        }
        if(dist.find(endGene) == dist.end())
            return -1;
        return dist[endGene];
    }
};