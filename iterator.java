import java.util.Iterator;
import java.util.List;

public class FlattenedIterator implements Iterator<Integer> 
{
  private Integer iter_index = 0;
  private List<Integer> m_list;
  public FlattenedIterator(List<Iterator<Integer>> subiterators) 
  {
    boolean isVisited; 
    while(true)
    {
      isVisited = false;
      for (var it : subiterators)
      {
        if (it.hasNext())
        {
          m_list.add(new Integer(it.next()));
          isVisited = true;
        }
      }
      if (!isVisited)
        break;
    }
  }

  @Override
  public boolean hasNext()
  {
    return m_list.size() > iter_index;
  }

  @Override
  public Integer next()
  {
    return m_list.get(iter_index++);
  }
}
