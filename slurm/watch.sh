watch -n 0.1 "echo ======PROGRESS====== && (cat data/PPO/0_steps/train.progress || true) && echo '' && echo =======STDOUT======= && (tail slurm/out.txt || true) && echo '' && echo =======STDERR======= && (tail slurm/err.txt || true) && echo '' && echo =======STATUS======= && scontrol show job $(cat slurm/sbatch_out.txt | awk '{print $4}') | grep JobState"