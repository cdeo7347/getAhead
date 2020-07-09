#include <vector>

class Iterator {
public:
  virtual bool hasNext() const = 0;
  virtual int next() = 0;
};

class FlattenedIterator : public Iterator {
private:
  std::vector<int> m_list;
  size_t m_count;
public:
  explicit FlattenedIterator(const std::vector<Iterator*>& subiterators)
  {
    m_list.reserve(subiterators.size());
    m_count = 0;
    bool isVisited = false;
    while(true)
    {
      isVisited = false;
      for (auto it : subiterators)
      {
        if (it->hasNext())
        {
          m_list.emplace_back(it->next());
          it++;
          isVisited = true;
        }
      }
      if (!isVisited)
        break;
    }
  }

  bool hasNext() const override {
    return m_list.size() > m_count;
  }
  
  int next() override {
    return m_list[m_count++];;
  }
};
