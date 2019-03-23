(defun max-dups ()
  (let ((start-year 1000) (stop-year 2013))
    (labels ((count-dups (n)
              (cond
                ((> n stop-year) 0)
                ((non-dup-p n) 0)
                (t (1+ (count-dups (1+ n)))))))
    (apply 'max
      (loop for year from start-year upto stop-year
        collect (count-dups year))))))

(defun max-non-dups ()
  (let ((start-year 1000) (stop-year 2013))
    (labels ((count-non-dups (n)
              (cond
                ((> n stop-year) 0)
                ((not (non-dup-p n)) 0)
                (t (1+ (count-non-dups (1+ n)))))))
      (apply 'max
        (loop for year from start-year upto stop-year
          collect (count-non-dups year))))))
