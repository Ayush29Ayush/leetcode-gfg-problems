class ZeroEvenOdd {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<int>counter=1;
    std::atomic<bool> zeroTurn = true;

public:
    ZeroEvenOdd(int n) 
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) 
    {
        std::unique_lock <std::mutex> lk(mtx);
        while(true)
        {
            cv.wait(lk,[this](){ return (counter>n || zeroTurn ); });
            if(counter>n)
                return;
            printNumber(0);
            zeroTurn= false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) 
    {
        std::unique_lock <std::mutex> lk(mtx);
        while(true)
        {
            cv.wait(lk,[this](){ return (counter>n || (counter % 2 == 0 && !zeroTurn) ); });
            if(counter>n)
                return;
            printNumber(counter);
            zeroTurn= true;
            ++counter;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) 
    {
        std::unique_lock <std::mutex> lk(mtx);
        while(true)
        {
            cv.wait(lk,[this](){ return (counter>n || (counter % 2 == 1 && !zeroTurn) ); });
            if(counter>n)
                return;
            printNumber(counter);
            zeroTurn= true;
            ++counter;
            cv.notify_all();
        }
    }
};