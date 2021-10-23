while(indices.empty() == false){
    //     int area;
    //     int top = indices.top();
    //     indices.pop();
    //     if(indices.empty()){ //Top has no left boundary i.e. all bars untill i have atleast hist[top] height
    //         area = hist[top]*i;
    //     }
    //     else{
    //         int prev_to_top = indices.top();
    //         int area = hist[top]*(i-prev_to_top-1);   //area of top = height of top * (right smaller boundary-left smaller boundary -1)
    //     }
    //     if(area>maxArea){
    //         maxArea = area;
    //     }
    //     //NOTE THAT WE ARE NOT UPDATING i BECAUSE WE WANT To REPEAT FOR ALL ELEMENT IN STACK UNTILL WE FIND SMALLER FOR hist[i].(THEN ONLY PREVIOUS TO TOP WILL BE LEFT BOUNDARY in next iterations)
    // }
    // return maxArea;