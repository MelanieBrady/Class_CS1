
// "static void main" must be defined in a public class.
public class Main {
    
    private static double binarySearch(double lowerBound, double upperBound, double previousMidpoint) {
        // first get the midpoint like normal
        double midPoint = lowerBound + (upperBound - lowerBound) / 2;
        
        // the base camse - this will make more sense after you read the section below it,
        // but basically, we're always going down the "smaller" path at each recursive call,
        // so if the difference between the current value and the previous value is
        // within our margin of error, then we've found the value that minimizes cos.
        if(Math.abs(Math.cos(previousMidpoint) - Math.cos(midPoint)) < 0.00005) {
            return midPoint;
        }
        
        // now we need to decide if we should go up or down, like a normal bin. search.
        // because cos decreases and increases again in one period, we have to look ahead
        // to the next set of midpoints (the midpoints of "low to mid" and "mid to high")
        // to see which one will get us the smaller value - that's always the one we want
        // essentially, we have this:
        //  (low)-------------(mid)-------------(high)
        // and we want to find this:
        //  (low)------(lower-mid)-------(mid)------(upper-mid)-------(high)
        // and see if lower-mid or upper-mid will give us the smaller value; that way
        // we know which half of the search range to "cut off"
        double lowerMidPoint = lowerBound + (midPoint - lowerBound) / 2;
        double upperMidPoint = midPoint + (upperBound - midPoint) / 2;
        // now check which one gives us the smaller value and go down that recursive path
        if(Math.cos(lowerMidPoint) < Math.cos(upperMidPoint)) {
            return binarySearch(lowerBound, midPoint, midPoint);
        } else {
            return binarySearch(midPoint, upperBound, midPoint);
        }
    }
    
    
    public static void main(String[] args) {
        System.out.println(binarySearch(0.0, 3.14, Double.MAX_VALUE));
        // output: 3.1369335937500002 (acceptably close to pi)
    }
}
