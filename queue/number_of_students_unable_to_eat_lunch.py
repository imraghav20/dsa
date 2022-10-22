class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count = len(students)
        while(sandwiches and students and sandwiches[0] in students):
            if(sandwiches[0]!=students[0]):
                students.append(students[0])
                print(students)
                students.pop(0)
            else:
                students.pop(0)
                sandwiches.pop(0)
                count-=1
        return count
