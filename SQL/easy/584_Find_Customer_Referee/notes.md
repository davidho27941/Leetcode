# Recyclable and Low Fat Products

## Infomation

* Difficulty: Easy

* Information Schema:

```
Table: Customer

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
In SQL, id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
```

## Question

Find the names of the customer that are not referred by the customer with id = 2.

Return the result table in any order.

The result format is in the following example.

## Example

```
Input: 
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
Output: 
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
```

## Solving Strategy

The question ask us to find the customers not referred by `id=2`. The `referee_id` column can be either `null` or integer. In this case, a customer who's `referee_id` fulfill the requirement when:

* When `referee_id` is null
* When `referee_id` is not `2`

## Solution

* MySQL

```
SELECT name 
FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL;
```