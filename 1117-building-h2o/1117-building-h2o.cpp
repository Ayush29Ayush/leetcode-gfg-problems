class H2O 
{
    int hcount = 0, ocount = 0;             // total count of atoms received, whether or not they have been released
    int atomsReleased = 0;                  // number of calls to releaseHydrogen and releaseOxygen that have completed
    std::condition_variable cv;
    std::mutex mtx;                         // protects cv, counts
    
    
public:
    H2O() {
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        std::unique_lock<std::mutex> lk(mtx);
        int id = hcount / 2;
        ++hcount;

        waitForMolecule(id, lk, releaseHydrogen);
    }

    void oxygen(function<void()> releaseOxygen)
    {
        std::unique_lock<std::mutex> lk(mtx);
        int id = ocount;
        ++ocount;
        
        waitForMolecule(id, lk, releaseOxygen);
    }
    
private:
    //
    //  Waits until exactly {id} H2O molecules have been completely released,
    //  then invokes {releaseFunction} and notifies all threads that {atomsReleased} has changed.
    //
    void waitForMolecule(int id, std::unique_lock<std::mutex> &lk, function<void()> releaseFunction)
    {
        cv.wait(lk, [this, id]{ return id == atomsReleased / 3; });

        releaseFunction();
        
        ++atomsReleased;
        cv.notify_all();
    }
};