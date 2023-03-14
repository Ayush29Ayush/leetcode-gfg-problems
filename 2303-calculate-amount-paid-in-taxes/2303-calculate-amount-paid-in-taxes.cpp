// do DRY RUN on brackets = [[3,50],[7,10],[12,25]], income = 10
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) 
    {    
        double tax = 0; 
        
        // calc for 0th index first
        if(brackets[0][0]<=income) 
            tax=(brackets[0][0]*brackets[0][1]/100.0);         
        else if(brackets[0][0]>income)
            return (income*brackets[0][1]/100.0);
            
        
        // now calc fron 1st index to last index
        for(int i=1; i<brackets.size(); i++)
        {
            // if upper is less than income means we can consider it so [upper(i) - upper(i-1)]*tax percent
            if(brackets[i][0]<=income)
                    tax += ((brackets[i][0]-brackets[i-1][0])*brackets[i][1]/100.0);
            // if upper is more than income means we can not consider it so use income directly => [income - upper(i-1)]*tax percent
            else if(brackets[i][0]>income) 
            {
                tax += ((income-brackets[i-1][0])*brackets[i][1]/100.0);
                break;
            }
        }
        return tax;
        
    }
};