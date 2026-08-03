class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string current = "";

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {

                if (current == "" || current == ".") {
                    // Ignore
                }
                else if (current == "..") {

                    if (!st.empty())
                        st.pop();
                }
                else {
                    st.push(current);
                }

                current = "";
            }
            else {
                current += path[i];
            }
        }

        vector<string> folders;

        while (!st.empty()) {
            folders.push_back(st.top());
            st.pop();
        }

        reverse(folders.begin(), folders.end());

        if (folders.empty())
            return "/";

        string answer = "";

        for (string folder : folders)
            answer += "/" + folder;

        return answer;
    }
};