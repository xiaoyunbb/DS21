string TextEditor(string KeyboardInputs) {
    // Write your code here
    vector<char> c(555555);
    c.clear();
    string k;
    k.assign(KeyboardInputs);
    bool insert = true;
    int cursor = 0;
    auto N = KeyboardInputs.length();
    
    for(auto i = 0; i < N; i++){
        if(k[i] == '<'){
            if(cursor > 0) cursor--;
        }
        else if(k[i] == '>'){
            if(cursor < c.size()) cursor++; 
        }
        else if(k[i] == '@'){
            if(cursor != 0){
                cursor--;
                c.erase(c.begin() + cursor);
            }
        }
        else if(k[i] == '$') insert = !insert;
        else{
            if(insert){
                c.insert(c.begin() + cursor, k[i]);
                cursor++;
            }
            else{
                if(c.begin() + cursor != c.end()) c.erase(c.begin() + cursor);
                c.insert(c.begin() + cursor, k[i]);
                cursor++;
            }
        }
    }
    
    string output(c.begin(), c.end());
    return output;
}
