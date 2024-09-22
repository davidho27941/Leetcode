# Students and Examinations

## Infomation

* Difficulty: Easy

* Information Schema:

```
Table: Students

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id is the primary key (column with unique values) for this table.
Each row of this table contains the ID and the name of one student in the school.
 

Table: Subjects

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| subject_name | varchar |
+--------------+---------+
subject_name is the primary key (column with unique values) for this table.
Each row of this table contains the name of one subject in the school.
 

Table: Examinations

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| subject_name | varchar |
+--------------+---------+
There is no primary key (column with unique values) for this table. It may contain duplicates.
Each student from the Students table takes every course from the Subjects table.
Each row of this table indicates that a student with ID student_id attended the exam of subject_name.
```

## Question

Write a solution to find the number of times each student attended each exam.

Return the result table ordered by student_id and subject_name.

The result format is in the following example.

## Example

```
Input: 
Students table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 1          | Alice        |
| 2          | Bob          |
| 13         | John         |
| 6          | Alex         |
+------------+--------------+
Subjects table:
+--------------+
| subject_name |
+--------------+
| Math         |
| Physics      |
| Programming  |
+--------------+
Examinations table:
+------------+--------------+
| student_id | subject_name |
+------------+--------------+
| 1          | Math         |
| 1          | Physics      |
| 1          | Programming  |
| 2          | Programming  |
| 1          | Physics      |
| 1          | Math         |
| 13         | Math         |
| 13         | Programming  |
| 13         | Physics      |
| 2          | Math         |
| 1          | Math         |
+------------+--------------+
Output: 
+------------+--------------+--------------+----------------+
| student_id | student_name | subject_name | attended_exams |
+------------+--------------+--------------+----------------+
| 1          | Alice        | Math         | 3              |
| 1          | Alice        | Physics      | 2              |
| 1          | Alice        | Programming  | 1              |
| 2          | Bob          | Math         | 1              |
| 2          | Bob          | Physics      | 0              |
| 2          | Bob          | Programming  | 1              |
| 6          | Alex         | Math         | 0              |
| 6          | Alex         | Physics      | 0              |
| 6          | Alex         | Programming  | 0              |
| 13         | John         | Math         | 1              |
| 13         | John         | Physics      | 1              |
| 13         | John         | Programming  | 1              |
+------------+--------------+--------------+----------------+
Explanation: 
The result table should contain all students and all subjects.
Alice attended the Math exam 3 times, the Physics exam 2 times, and the Programming exam 1 time.
Bob attended the Math exam 1 time, the Programming exam 1 time, and did not attend the Physics exam.
Alex did not attend any exams.
John attended the Math exam 1 time, the Physics exam 1 time, and the Programming exam 1 time.
```

## Solving Strategy

The solution for this question is quite complicated. Directly select and filter the joined table may loss some records. We will solve this problem with following steps.

1. Cross Join `Students` and `Subject` to get complete student-subject mapping. (Name as `merge_student_with_subject`)
2. Apply `GROUP BY` clause to `Examinations` table, and select the `student_id`, `subject_name` and `COUNT(*)` as `attended_exams`. (Name as `student_attended_exam`)
3. Join `merge_student_with_subject` and `student_attended_exam` using `LEFT JOIN` on `student_id` and `subject_name`.
4. Since the `attended_exams` can be null, so we need to use `IFNULL` clause to cast `NULL` as `0`.
5. Select `student_id`, `student_name`, `subject_name`, and `attended_exams`, then order the output by `student_id` and `student_name`.

## Solution

* MySQL

```
WITH merge_student_with_subject AS (
    SELECT 
        S.student_id,
        S.student_name,
        Sub.subject_name
        -- IFNULL(attended_exams, 0) AS attended_exams
    FROM Students AS S
    CROSS JOIN Subjects AS Sub
), 
student_attended_exam AS (
    SELECT 
        student_id,
        subject_name,
        COUNT(*) AS attended_exams
    FROM Examinations
    GROUP BY student_id, subject_name
)

SELECT
    merge_student_with_subject.student_id AS student_id,
    merge_student_with_subject.student_name AS student_name,
    merge_student_with_subject.subject_name AS subject_name,
    IFNULL(student_attended_exam.attended_exams, 0) as attended_exams
FROM merge_student_with_subject
LEFT JOIN student_attended_exam
    ON merge_student_with_subject.student_id = student_attended_exam.student_id
    AND merge_student_with_subject.subject_name = student_attended_exam.subject_name
ORDER by 
    merge_student_with_subject.student_id, merge_student_with_subject.subject_name;
```
