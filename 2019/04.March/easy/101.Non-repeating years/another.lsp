(defun non-dup-p (num)
  (let ((num-str (write-to-string num)))
    (equal num-str (remove-duplicates num-str))))

(defun non-repeating-years (start end)
  (loop for y from start upto end
    :sum (if (non-dup-p y) 1 0)))
