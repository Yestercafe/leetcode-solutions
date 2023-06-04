import (
    "github.com/emirpasic/gods/queues/priorityqueue"
    "github.com/emirpasic/gods/utils"
)

type Worker struct {
    cost int
    idx int
    isLeft bool
}

func NewWorker(cost, idx int, isLeft bool) Worker {
    return Worker {
        cost: cost,
        idx: idx,
        isLeft: isLeft,
    }
}

func byPriority(a, b interface{}) int {
    wa, wb := a.(Worker), b.(Worker)
    if wa.cost != wb.cost {
        return utils.IntComparator(wa.cost, wb.cost)
    } else {
        return utils.IntComparator(wa.idx, wb.idx)
    }
}

func totalCost(costs []int, k int, cdt int) (ans int64) {
    pq := priorityqueue.NewWith(byPriority)
    n := len(costs)
    l, r := cdt, n - cdt - 1
    if 2 * cdt >= n {
        for i, cost := range costs {
            pq.Enqueue(NewWorker(cost, i, true))
        }
    } else {
        for i := 0; i < cdt; i++ {
            pq.Enqueue(NewWorker(costs[i], i, true))
            pq.Enqueue(NewWorker(costs[n-1-i], n-1-i, false))
        }
    }

    for ; k != 0; k-- {
        f, _ := pq.Dequeue()
        ans += int64(f.(Worker).cost)
        if l > r {
            continue
        }
        if (f.(Worker).isLeft) {
            pq.Enqueue(NewWorker(costs[l], l, true))
            l++
        } else {
            pq.Enqueue(NewWorker(costs[r], r, false))
            r--
        }
    }

    return
}

