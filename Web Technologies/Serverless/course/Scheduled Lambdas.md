**Scheduled Lambdas** allow you to run AWS Lambda functions on a regular, automated schedule. This is typically achieved by using Amazon **CloudWatch Events** (now part of **Amazon EventBridge**) to trigger Lambda functions at specified intervals, such as every hour, daily, or even on more complex cron schedules.

In the context of the **Serverless Framework**, you can easily set up scheduled Lambdas by specifying the `schedule` event in your `serverless.yml` file.

### Key Concepts

1. **Cron Expressions**: CloudWatch Events (or EventBridge) uses cron-like expressions to specify the schedule.
   - Cron expressions are used to define recurring events with specific times and frequencies. For example, `rate(1 day)` would trigger an event every day, and `cron(0 10 * * ? *)` would trigger an event every day at 10 AM UTC.
   
2. **Rate Expressions**: These are simpler than cron expressions and define fixed intervals (e.g., every 5 minutes, every hour, etc.).
   - Examples:
     - `rate(5 minutes)` — every 5 minutes.
     - `rate(1 hour)` — every 1 hour.
     - `rate(1 day)` — every 24 hours.

### Setting Up Scheduled Lambdas with Serverless Framework

Here’s how to configure scheduled Lambda functions in **Serverless Framework** using either **rate expressions** or **cron expressions**.

### Example 1: Simple Scheduled Lambda (Using Rate Expression)

In this example, the Lambda function will run every hour.

1. **Create a serverless service**:

   If you don’t already have a service, create one using the Serverless Framework:
   ```bash
   serverless create --template aws-nodejs --path scheduled-service
   cd scheduled-service
   ```

2. **Edit `serverless.yml`**:

   In the `serverless.yml` file, add an event for the Lambda function that specifies a schedule.

   ```yaml
   service: scheduled-service

   provider:
     name: aws
     runtime: nodejs14.x

   functions:
     scheduledFunction:
       handler: handler.scheduledFunction
       events:
         - schedule:
             rate: rate(1 hour)  # Runs every 1 hour
             enabled: true  # Make sure the function is enabled

   # Optionally, you can specify the region and other settings for your service
   provider:
     region: us-east-1
   ```

3. **Write the Lambda function**:

   Edit the `handler.js` file to write the function that will be triggered on the schedule.

   ```javascript
   module.exports.scheduledFunction = async (event) => {
     console.log('Scheduled function triggered', event);
     return {
       statusCode: 200,
       body: JSON.stringify({ message: 'Scheduled function executed successfully' }),
     };
   };
   ```

4. **Deploy the Service**:

   Deploy your service to AWS with the following command:

   ```bash
   serverless deploy
   ```

   After deployment, the Lambda function will be triggered every hour based on the schedule defined in the `serverless.yml` file.

---

### Example 2: Scheduled Lambda Using Cron Expression

If you want more control over the timing (e.g., run at a specific time every day), you can use **cron expressions**.

Here’s an example where a Lambda function runs every day at 10 AM UTC:

1. **Edit `serverless.yml`**:

   Modify the `serverless.yml` file to use a cron expression for the schedule:

   ```yaml
   service: scheduled-cron-service

   provider:
     name: aws
     runtime: nodejs14.x

   functions:
     cronFunction:
       handler: handler.cronFunction
       events:
         - schedule:
             cron: cron(0 10 * * ? *)  # Runs every day at 10:00 AM UTC
             enabled: true  # Ensure the function is enabled

   # Optionally specify region and other settings
   provider:
     region: us-east-1
   ```

2. **Write the Lambda function**:

   In `handler.js`, write the function that will execute when triggered by the cron schedule.

   ```javascript
   module.exports.cronFunction = async (event) => {
     console.log('Cron job triggered', event);
     return {
       statusCode: 200,
       body: JSON.stringify({ message: 'Cron job executed successfully' }),
     };
   };
   ```

3. **Deploy the Service**:

   Deploy the service using:

   ```bash
   serverless deploy
   ```

   This will deploy the scheduled Lambda function, which will run every day at **10 AM UTC**.

---

### Understanding Cron Expressions

Cron expressions are more flexible than rate expressions and are commonly used for scheduled tasks that need to occur at specific times. Here’s a breakdown of a cron expression:

```bash
cron(Minutes Hours Day-of-month Month Day-of-week Year)
```

- **Minutes**: 0-59
- **Hours**: 0-23 (24-hour format)
- **Day-of-month**: 1-31
- **Month**: 1-12
- **Day-of-week**: 1-7 (1 = Sunday, 7 = Saturday)
- **Year**: Optional

For example:
- `cron(0 10 * * ? *)` — Runs at 10 AM UTC every day.
- `cron(0 0 1 * ? *)` — Runs at midnight UTC on the first day of every month.
- `cron(0 9 ? * MON-FRI *)` — Runs at 9 AM UTC Monday through Friday.

---

### Example 3: Using a Scheduled Lambda to Clean Up Old Data

Here’s an example of a scheduled Lambda that runs every 24 hours to clean up old data (perhaps from a database or S3 bucket):

1. **Edit `serverless.yml`**:

   Configure the event to trigger the function every 24 hours.

   ```yaml
   service: cleanup-service

   provider:
     name: aws
     runtime: nodejs14.x

   functions:
     cleanupOldData:
       handler: handler.cleanupOldData
       events:
         - schedule:
             rate: rate(1 day)  # Runs every day
             enabled: true

   resources:
     # Add any resources you need (e.g., DynamoDB tables, S3 buckets)
   ```

2. **Write the Cleanup Function**:

   The function could be written as follows in `handler.js`:

   ```javascript
   module.exports.cleanupOldData = async (event) => {
     console.log('Starting cleanup of old data...');
     // Logic for cleaning up old data (e.g., delete records from a database)
     return {
       statusCode: 200,
       body: JSON.stringify({ message: 'Old data cleaned up successfully' }),
     };
   };
   ```

3. **Deploy**:

   Deploy the service using:

   ```bash
   serverless deploy
   ```

   This function will automatically execute every day to perform the cleanup.

---

### Additional Configuration Options for Scheduled Events

- **Enabled/Disabled**: You can enable or disable scheduled events with the `enabled` property.
  ```yaml
  enabled: false  # This disables the scheduled event
  ```

- **Input to the Function**: You can pass custom input to the Lambda when it's triggered. For example:
  ```yaml
  events:
    - schedule:
        rate: rate(1 day)
        input:
          key: value
  ```

---

### Conclusion

Scheduled Lambdas are a powerful way to automate tasks in serverless applications. You can configure them using simple **rate expressions** or more flexible **cron expressions** in the `serverless.yml` file. Whether you're running periodic cleanups, sending scheduled emails, or performing other automated tasks, scheduled Lambdas provide an easy and scalable way to handle recurring functions in AWS.

