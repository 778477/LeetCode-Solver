
//Accepted    400 ms    java
public class Solution {
    public ListNode mergeKLists(ArrayList<ListNode> lists) {
        ListNode head, tmp, p;
        Q = new PriorityQueue<ListNode>(1024, new cmp());
        Q.clear();
        for (int i = 0; i < lists.size(); i++)
        {
            tmp = lists.get(i);
            if(tmp != null)
                Q.offer(tmp);
        }
        tmp = Q.peek();
        Q.poll();
        if (tmp != null && tmp.next != null)
            Q.offer(tmp.next);
        head = tmp;
        while (!Q.isEmpty()) {
            p = Q.peek();
            Q.poll();
            if (p.next != null)
                Q.offer(p.next);
            tmp.next = p;
            tmp = p;
        }
        return head;
    }

    class cmp implements Comparator<ListNode> {
        public int compare(ListNode a, ListNode b) {
            return a.val - b.val;
        }
    }

    private PriorityQueue<ListNode> Q;
}


