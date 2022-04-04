#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <queue>
#include <map>

using namespace std;

enum InstType {
    Add = 0,
    Sub,
    Div,
    Load,
    Store,
    Unimplemented
};

class Inst{
public:

    friend ostream& operator<<(ostream& os, Inst& inst) {
        os << inst.GetType();
        return os;
    }

    Inst(InstType type): m_type(type)
    {

    }
    void SetType(InstType type)
    {
        m_type = type;
    }
    
    InstType GetType()
    {
        return m_type;
    }
private:
    InstType m_type = Unimplemented;
};


/*
** Fifo通过std::map保证存入的元素按照first严格保序
*/
class Fifo{
public:

    friend ostream& operator<<(ostream& os, Fifo& f) {
        if(!f.q.empty()){
            for(auto it = f.q.cbegin(); it != f.q.cend(); it++) {
                os << "Timing: " << it->first << " , InstType: " << it->second->GetType() << endl;
            }
        } else {
            cout << "No Ready Element in Fifo!" << endl;
        }
        return os;
    }

    Fifo(int depth, int lat, const char* name): m_maxSize(depth), m_lat(lat), m_name(name)
    {
        // q.resize(depth);  // resize会限制最大深度吗？超过深度会报错吗？std::queue没有resize方法？
        // 哪些数据结构有resize方法？ 为什么其他的没有？
    }
    virtual ~Fifo()
    {

    }

    bool write(int now, Inst* inst)
    {
        if(q.size() < m_maxSize) {  // q.size()返回的是map的表项个数吗？
            q.insert(std::make_pair(now + m_lat, inst));
            return true;
        } else {
            cout << "Fifo [" << m_name << "] is Full!" << endl;
            return false;
        }
    }

    Inst* read(int now)  // 要求读出前面的指令，并从Fifo中删除
    {
        if(!q.empty()){
            for(auto it = q.cbegin(); it != q.cend(); it++) {
                if(it->first <= now) {
                    Inst* tmp = it->second;
                    q.erase(it);
                    return tmp;
                }
            }
        } else {
            cout << "No Ready Element in Fifo!" << endl;
            return nullptr;
        }
        return nullptr;
    }

    Inst* peek(int now)  // 要求读出前面的指令，并从Fifo中删除
    {
        if(!q.empty()){
            for(auto it = q.cbegin(); it != q.cend(); it++) {
                if(it->first <= now) {
                    Inst* tmp = it->second;
                    return tmp;
                }
            }
        } else {
            cout << "No Ready Element in Fifo!" << endl;
            return nullptr;
        }
        return nullptr;
    }

private:
    int m_maxSize;
    int m_lat;  // Fifo的默认时延
    const char* m_name;
    map<int, Inst*> q;  // map的正确用法？ map会默认按照first排序？排序规则是什么？
    // 默认按照第一个参数升序排列
    // std::queue<entry*> q;  // queue不是模板类？
    // vector<Entry*> q;
    // vector pop_front之后后面的元素会向前前进一个索引吗？
    typedef map<int, Inst*>::iterator QItem;    // iterator怎么用？不是作用域解析符吗？
};