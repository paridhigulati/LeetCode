# Write your MySQL query statement below
SELECT s1.Score , (select count(distinct score)  from 
    Scores s2
where 
     s1.score <= s2.score)
      as 'rank'
     from Scores s1
    

order by s1.score desc