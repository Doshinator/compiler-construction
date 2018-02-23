#include <map>
#include <memory>


template <typename K, typename V>
class IMap{
    public:
    map<K, V> hm;
    IMap() { (new map<K, V>());}
    
      V ref(K x){
        V r = hm.get(x);
        if( r == NULL){
            throw new runtime_error(x + " not found in hash map");
        }
        return r;
    }

    IMap<K, V> set(K x, V v){
        map<K, V> hmp = new map<K, V>(hm);
        hmp.put(x, v);
        return new IMap<K, V>(hmp);
    }

    IMap<K, V> merge(IMap<K,V> o){
        map<K, V> hmp = new map<K, V>(hm);
        hmp.putAll(o.hm);
        return new IMap<K, V>(hmp);
    }

    private:
    IMap(map<K,V> hm){ this->hm = hm;}
};




class IMap<K,V>{



};