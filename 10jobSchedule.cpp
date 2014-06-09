//有n个任务需要完成（编号1到n），任务之间有一些依赖关系，如果任务a依赖于任务b和c，那么只有当任务b和任务c完成之后才能完成任务a。给定所有的依赖关系，判断这些任务是否能够完成。如果能够完成，请给出一个合法的任务完成序列。
//
//样例：
//n=5
//1->2,3
//3->4
//
//上述样例中任务1依赖于任务2和任务3，任务3依赖于任务4，那么存在合法的任务完成序列4,3,2,1,5

#include <map>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
typedef int JobID;

/*
 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
 */
 /*
    id are from 1 to n
 */
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                   vector<JobID> &result) {
    map<JobID, vector<JobID>> rmap;
    vector<int> indeg(n+1, 0);
    for (map<JobID, vector<JobID> >::const_iterator it = deps.begin(); it != deps.end(); it++) {
        indeg[it->first] = it->second.size();
        for (int i = 0; i < it->second.size(); i++) {
            rmap[it->second[i]].push_back(it->first);
        }
    }
    stack<JobID> stak;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            stak.push(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (stak.empty()) return false;
        JobID id = stak.top();
        stak.pop();
        result[i] = id;
        for (int j = 0; j < rmap[id].size(); j++) {
            indeg[rmap[id][j]]--;
            if (indeg[rmap[id][j]] == 0) {
                stak.push(rmap[id][j]);
            }
        }
    }
    return true;
}